#include "string.h"
#include <utility>
#include <vector>
#include <windows.h>
#include <vector>

String create_heavy_string() {
    String local("Very long text inside a temporary object");
    return local; // Здесь работает RVO/NRVO или конструктор перемещения
}

int main() {

    SetConsoleOutputCP(CP_UTF8); 

    std::cout << "--- ШАГ 1: Инициализация ---\n";
    String a("Alpha"); // Обычный конструктор
    String b("Beta");  // Обычный конструктор

    std::cout << "\n--- ШАГ 2: Копирующее присваивание ---\n";
    b = a; // Ожидаем [COPY ASSIGNMENT]

    std::cout << "\n--- ШАГ 3: Перемещение ---\n";
    // std::move превращает 'a' (lvalue) в xvalue.
    // Вызывается конструктор перемещения для 'c'
    String c = std::move(a); 

    std::cout << "\n--- ШАГ 4: Возврат из функции ---\n";
    // Перемещение временного объекта, возвращенного из функции
    String d = create_heavy_string();

    std::cout << "\n--- ШАГ 5: Состояние объектов ---\n";
    std::cout << "a: "; a.print();
    std::cout << "b: "; b.print();
    std::cout << "c: "; c.print();
    std::cout << "d: "; d.print();

    std::vector<String> list;

    std::cout << "\n--- ШАГ 6: Добавление в вектор ---\n";

    for (size_t i = 0; i < 10; i++)
    {
        list.push_back(String("String"));
        std::cout << "\n\n [USER] Added new string to the vector \n\n";
    }
    
    std::cout << "\n--- ШАГ 7: Финал программы ---\n";
    return 0;
}