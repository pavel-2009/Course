#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <type_traits>
#include <array>


template<typename T>
class NDArray {
    private:
        std::vector<T> data_;
        std::vector<size_t> shape_;
        std::vector<size_t> strides_;

    public:
        NDArray(const std::vector<size_t>& shape) : shape_(shape) {
            size_t total_size = 1;
            for (size_t dim : shape) {
                total_size *= dim;
            }
            data_.resize(total_size, T()); // Инициализируем нулями по умолчанию
            strides_ = compute_strides(shape);
        }

        T* data() {
            return data_.data();
        }

        // Возвращает сырой указатель на данные для NDView
        const T* data() const {
            return data_.data();
        }

        const std::vector<size_t>& shape() const {
            return shape_;
        }

        const std::vector<size_t>& strides() const {
            return strides_;
        }

        const size_t size() const {
            return data_.size();
        }

        void fill(const T& value) {
            std::fill(data_.begin(), data_.end(), value);
        }

        template<typename... Args>
        T& operator()(Args... indices) {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");
            
            std::array<size_t, sizeof...(Args)> idx{static_cast<size_t>(indices)...};
            
            if (idx.size() != shape_.size()) {
                throw std::invalid_argument("Dimension mismatch.");
            }
            
            size_t offset = 0;
            for (size_t i = 0; i < idx.size(); ++i) {
                if (idx[i] >= shape_[i]) {
                    throw std::out_of_range("Index out of bounds.");
                }
                offset += idx[i] * strides_[i];
            }

            return data_[offset];
        }

        template<typename... Args>
        const T& operator()(Args... indices) const {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");
            
            if (sizeof...(indices) != shape_.size()) {
                throw std::invalid_argument("Dimensions mismatch.");
            }

            size_t i = 0;
            size_t offset = 0;
            ((offset += static_cast<size_t>(indices) * strides_[i++]), ...);
            return data_[offset];
        }

        template<typename... Args>
        T& at(Args... indices) {
            static_assert((std::is_convertible_v<Args, size_t> && ...), "All indices must be convertible to size_t.");
            
            if (sizeof...(indices) != shape_.size()) {
                throw std::invalid_argument("Dimensions mismatch.");
            }

            size_t i = 0;
            size_t offset = 0;
            ((offset += static_cast<size_t>(indices) * strides_[i++]), ...);
            return data_[offset];
        }
        
        private:
        std::vector<size_t> compute_strides(const std::vector<size_t>& shape) {
            std::vector<size_t> strides(shape.size());
            size_t stride = 1;
            for (size_t i = shape.size(); i-- > 0; ) {
                strides[i] = stride;
                stride *= shape[i];
            }
            return strides;
        }

        public:

        void reshape(const std::vector<size_t>& new_shape) {
            size_t new_total_size = 1;
            for (size_t dim : new_shape) {
                new_total_size *= dim;
            }
            if (new_total_size != data_.size()) {
                throw std::invalid_argument("New shape must have the same total size as the original shape.");
            }
            shape_ = new_shape;
            strides_ = compute_strides(new_shape);
        }

        NDArray<T> operator+(const NDArray<T>& other) const {
            if (shape_ != other.shape_) {
                throw std::invalid_argument("Shapes of the two NDArrays must be the same for addition.");
            }
            NDArray<T> result(shape_);
            for (size_t i = 0; i < data_.size(); ++i) {
                result.data_[i] = data_[i] + other.data_[i];
            }
            return result;
        }

        NDArray<T> operator-(const NDArray<T>& other) const {
            if (shape_ != other.shape_) {
                throw std::invalid_argument("Shapes of the two NDArrays must be the same for subtraction.");
            }
            NDArray<T> result(shape_);
            for (size_t i = 0; i < data_.size(); ++i) {
                result.data_[i] = data_[i] - other.data_[i];
            }
            return result;
        }

        NDArray<T> operator*(const T& scalar) const {
            NDArray<T> result(shape_);
            for (size_t i = 0; i < data_.size(); ++i) {
                result.data_[i] = data_[i] * scalar;
            }
            return result;
        }

        NDArray<T> operator/(const T& scalar) const {
            if (scalar == T(0)) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            NDArray<T> result(shape_);
            for (size_t i = 0; i < data_.size(); ++i) {
                result.data_[i] = data_[i] / scalar;
            }
            return result;
        }

        T sum() const {
            T total{};
            for (const auto& val : data_) {
                total += val;
            }
            return total;
        }

        double mean() const {
            if (data_.empty()) {
                throw std::runtime_error("Cannot compute mean of an empty array.");
            }
            return static_cast<double>(sum()) / data_.size();
        }

        template<typename Func>
        void apply(Func func) {
            for (auto& val : data_) {
                val = func(val);
            }
        }
    
        NDArray<T> matmul(const NDArray<T>& other) const {
            if (shape_.size() != 2 || other.shape_.size() != 2) {
                throw std::invalid_argument("Both arrays must be 2D for matrix multiplication.");
            }
            if (shape_[1] != other.shape_[0]) {
                throw std::invalid_argument("Inner dimensions must match for matrix multiplication.");
            }

            std::vector<size_t> result_shape = {shape_[0], other.shape_[1]};
            NDArray<T> result(result_shape);

            for (size_t i = 0; i < shape_[0]; ++i) {
                for (size_t k = 0; k < other.shape_[1]; ++k) {
                    for (size_t j = 0; j < shape_[1]; ++j) {
                        result(i, k) += (*this)(i, j) * other(j, k);
                    }
                }
            }
            return result;
        }

        NDView<T> transpose() const {
            if (shape_.size() != 2) {
                throw std::invalid_argument("Transpose is only defined for 2D arrays.");
            }
            std::vector<size_t> new_shape = {shape_[1], shape_[0]};
            std::vector<size_t> new_strides = {strides_[1], strides_[0]};
            return NDView<T>(data_.data(), new_shape, new_strides);
        }

    };
