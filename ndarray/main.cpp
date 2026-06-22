#include <iostream>
#include "ndarray.h"
#include "ndview.h"

int main() {
    
    std::cout << "=== NDArray и NDView Пример ===" << std::endl;
    
    // Создаем 2D массив 3x4
    NDArray<int> arr({3, 4});
    
    std::cout << "\n1. Инициализация массива 3x4:" << std::endl;
    arr.fill(0);
    
    // Заполняем данные
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            arr(i, j) = i * 4 + j + 1;
        }
    }
    
    // Вывод всех элементов
    std::cout << "Элементы массива:" << std::endl;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            std::cout << arr(i, j) << " ";
        }
        std::cout << std::endl;
    }

    // Создаем View из массива (ИСПРАВЛЕНО: теперь arr.data() возвращает T*)
    std::cout << "\n2. Создание NDView из NDArray:" << std::endl;
    NDView<int> view(arr.data(), arr.shape(), arr.strides());
    std::cout << "View создан успешно!" << std::endl;
    
    // Доступ через view
    std::cout << "Доступ view(1, 2): " << view(1, 2) << std::endl;
    
    // Создаем View из первой строки массива
    std::cout << "\n3. NDView для первой строки:" << std::endl;
    NDView<int> row_view = view.row(0);
    std::cout << "Shape row_view: ";
    for (auto s : row_view.shape()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Элементы строки 0: ";
    for (size_t j = 0; j < row_view.shape()[0]; ++j) {
        std::cout << row_view(j) << " ";
    }
    std::cout << std::endl;
    
    // Информация о массиве
    std::cout << "\n4. Информация об NDArray:" << std::endl;
    std::cout << "Размер: " << arr.size() << std::endl;
    std::cout << "Shape: ";
    for (auto s : arr.shape()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    std::cout << "Strides: ";
    for (auto s : arr.strides()) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    
    // Тестирование обработки ошибок
    std::cout << "\n5. Тестирование границ:" << std::endl;
    try {
        arr(5, 5);  // Выход за границы
    } catch (const std::out_of_range& e) {
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }
    
    std::cout << "\nПрограмма завершена успешно!" << std::endl;
    return 0;
}
