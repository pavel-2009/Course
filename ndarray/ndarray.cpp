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

        // Оптимизированный оператор доступа через свертку (Fold Expressions)
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
        
        std::vector<size_t> compute_strides(const std::vector<size_t>& shape) {
            std::vector<size_t> strides(shape.size());
            size_t stride = 1;
            for (size_t i = shape.size(); i-- > 0; ) {
                strides[i] = stride;
                stride *= shape[i];
            }
            return strides;
        }
};
