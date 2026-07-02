#pragma once

#include <iostream>
#include <string>


enum class TaskPriority { LOW, MEDIUM, HIGH, CRITICAL };
enum class TaskStatus { TO_DO, IN_PROGRESS, DONE, ARCHIVED };

struct Task
{
    int id;
    std::string title;
    TaskPriority priority;
    TaskStatus status;

    Task(int t_id, const std::string t_title, TaskPriority t_priority)
        : id(t_id), title(std::move(t_title)), priority(t_priority), status(TaskStatus::TO_DO) {};

    Task(Task&& other) noexcept = default;
    Task& operator=(Task&& other) noexcept = default;

    Task(const Task& other) = delete;
    Task& operator=(const Task& other) = delete;
};
