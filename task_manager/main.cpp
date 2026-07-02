#include "task_manager.h"
#include <iostream>

int main() {
    TaskManager manager;

    // Добавляем задачи. Строки будут перемещены, копирования не происходит.
    manager.add_task(101, "Fix memory leak in allocator", TaskPriority::HIGH);
    manager.add_task(102, "Write unit tests for storage", TaskPriority::LOW);
    manager.add_task(103, "DB CONNECTION LOST!", TaskPriority::CRITICAL); // Станет первой в очереди

    // Выполняем две задачи
    manager.execute_next(); // Выполнит 103
    manager.execute_next(); // Выполнит 101

    manager.sort_archive_by_priority();

    manager.print_state();

    // Пример кастомного поиска в векторе с помощью лямбда-функции.
    // Ищем в архиве задачи с высоким (HIGH) или критическим (CRITICAL) приоритетом.
    manager.find_in_archive([](const Task& task) {
        return task.priority == TaskPriority::HIGH || task.priority == TaskPriority::CRITICAL;
    });

    return 0;
};