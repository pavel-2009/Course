#pragma once
#include "task.h"
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <functional>


class TaskManager {
private:
    std::vector<Task> global_archive;
    std::deque<Task> execution_pipeline;
    std::list<std::string> event_logger;

    void log_event(std::string message);

public:
    TaskManager();

    // Передаем title по значению и делаем std::move внутрь
    void add_task(int id, std::string title, TaskPriority priority);
    
    void execute_next();

    void find_in_archive(const std::function<bool(const Task&)>& predicate) const;

    void sort_archive_by_priority();

    void print_state() const;
};