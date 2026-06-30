#include "task_manager.h"
#include <iostream>
#include <algorithm>

TaskManager::TaskManager() {
    // Оптимизация памяти под вектор сразу, чтобы избежать реаллокаций на старте
    global_archive.reserve(100); 
}

void TaskManager::log_event(std::string message) {
    // Перемещаем строку прямо в узел списка. Ноль копирований.
    event_logger.emplace_back("[SYSTEM LOG]: " + std::move(message));
}

void TaskManager::add_task(int id, std::string title, TaskPriority priority) {
    // Конструируем объект прямо на месте внутри deque, избегая лишних временных объектов
    if (priority == TaskPriority::CRITICAL) {
        execution_pipeline.emplace_front(id, std::move(title), priority);
        log_event("Critical task pushed to front.");
    } else {
        execution_pipeline.emplace_back(id, std::move(title), priority);
        log_event("Standard task pushed to back.");
    }
}

void TaskManager::execute_next() {
    if (execution_pipeline.empty()) {
        log_event("Execution failed: pipeline empty.");
        return;
    }

    // Извлекаем задачу через move-семантику
    Task current_task = std::move(execution_pipeline.front());
    execution_pipeline.pop_front(); 

    std::string task_info = current_task.title;
    
    // Перемещаем задачу в вектор-архив. 
    // Поскольку наш Task имеет нотифицированный `noexcept` move-конструктор, 
    // вектор сделает это максимально эффективно.
    global_archive.push_back(std::move(current_task));
    
    log_event("Successfully executed task: " + task_info);
}

void TaskManager::find_in_archive(const std::function<bool(const Task&)>& predicate) const {
    std::cout << "\n--- Search Results in Archive ---\n";
    bool found = false;
    // Линейный обход вектора идеален благодаря локальности кэша
    for (const auto& task : global_archive) {
        if (predicate(task)) {
            std::cout << "Found: [" << task.id << "] " << task.title << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "No tasks matched the criteria.\n";
}

void TaskManager::sort_archive_by_priority() {
    std::sort(global_archive.begin(), global_archive.end(), [](const Task& a, const Task& b) {
        return static_cast<int>(a.priority) > static_cast<int>(b.priority);
    });

    log_event("Archive succesfully sorted.");

    return;
}

void TaskManager::print_state() const {
    std::cout << "\n=========================================\n";
    std::cout << "PIPELINE SIZE: " << execution_pipeline.size() 
              << " | ARCHIVE SIZE: " << global_archive.size() << "\n";
    std::cout << "=========================================\n";
    
    std::cout << "\nActive Pipeline Items:\n";
    for (const auto& task : execution_pipeline) {
        std::cout << " -> [" << task.id << "] " << task.title << " (Priority: " << static_cast<int>(task.priority) << ")\n";
    }

    std::cout << "\nSystem Logs:\n";
    for (const auto& log : event_logger) {
        std::cout << log << "\n";
    }
}