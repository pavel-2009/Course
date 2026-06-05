#include <iostream>
#include <string>


class Task {
    private:
        int id;
        std::string text;

    public:

        Task(int taskId, std::string taskText) {
            id = taskId;
            text = taskText;
        }

        void print() {
            std::cout << "[" << text << "]" << std::endl;
        }
};


int main() {
    Task t1(1, "Learn OOP");

    t1.print();

    return 0;
}
