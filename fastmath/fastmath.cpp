#include <cmath>
#include <stdexcept>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

py::array_t<double> pairwise_distance(
    py::array_t<double> A,
    py::array_t<double> B)
{
    auto bufA = A.request();
    auto bufB = B.request();

    if (bufA.ndim != 2 || bufB.ndim != 2)
    {
        throw std::runtime_error("Both inputs must be 2D arrays");
    }

    const size_t N = bufA.shape[0];
    const size_t D = bufA.shape[1];

    const size_t M = bufB.shape[0];

    if (bufB.shape[1] != D)
    {
        throw std::runtime_error("Dimension mismatch");
    }

    double* a = static_cast<double*>(bufA.ptr);
    double* b = static_cast<double*>(bufB.ptr);

    py::array_t<double> result({N, M});

    auto bufR = result.request();
    double* r = static_cast<double*>(bufR.ptr);

    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            double sum = 0.0;

            for (size_t k = 0; k < D; ++k)
            {
                double diff =
                    a[i * D + k] -
                    b[j * D + k];

                sum += diff * diff;
            }

            r[i * M + j] = std::sqrt(sum);
        }
    }

    return result;
}

PYBIND11_MODULE(fastmath, m)
{
    m.doc() = "Fast pairwise distance computation";

    m.def(
        "pairwise_distance",
        &pairwise_distance,
        "Compute pairwise Euclidean distances"
    );
}