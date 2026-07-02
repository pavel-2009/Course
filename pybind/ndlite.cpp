#include "ndlite.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

// Реализация обычных функций (не шаблонов)
double sum(std::vector<double> vec) {
    double total = 0.0;
    for (const auto& val : vec) {
        total += val;
    }
    return total;
}

double mean(std::vector<double> vec) {
    if (vec.empty()) {
        throw std::runtime_error("Cannot compute mean of an empty vector.");
    }
    return sum(vec) / vec.size();
}

// Подключение модуля pybind11
PYBIND11_MODULE(ndlite, m) {
    pybind11::class_<Vector<double>>(m, "Vector")
        .def(pybind11::init<std::vector<double>>()) 
        .def("norm", &Vector<double>::norm)
        .def("size", &Vector<double>::size)
        .def("dot", &Vector<double>::dot);

    m.def("sum", &sum, "Calculate the sum of a vector of doubles");
    m.def("mean", &mean, "Calculate the mean of a vector of doubles");
}
