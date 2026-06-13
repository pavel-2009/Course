#include "user.h"

void runSimulation() {
    std::cout << "--- START SIMULATION ---\n";

    auto alice = std::make_shared<User>("Alice");
    auto bob = std::make_shared<User>("Bob");
    auto charlie = std::make_shared<User>("Charlie");

    // Формируем граф связей
    alice->add_friend(bob);
    bob->add_friend(charlie);

    // Выводим списки друзей
    alice->print_friends();
    bob->print_friends();
    charlie->print_friends();

    std::cout << "--- END OF FUNCTION (Scope closing) ---\n";
}

int main() {
    runSimulation();
    std::cout << "Simulation finished. Check memory leaks logs above!\n";
    return 0;
}