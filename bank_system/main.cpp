#include "bank_account.h"
#include "user.h"
#include <iostream>
#include <string>
#include <vector>


int main() {
    BankAccount myAcc("TX-100200", "USD", 500.0);
    myAcc.deposit(150.0);
    myAcc.withdraw(50.0);
    myAcc.print_history();
    
    // Создаем пользователя
    User user1("USR-9921", "Alex Marconi");

    // Открываем ему два счета
    user1.open_account("ACC-USD-001", "USD", 1000.0);
    user1.open_account("ACC-EUR-002", "EUR", 500.0);

    // Выводим инфо
    user1.print_user_info();

    // Пытаемся найти счет и провести операцию
    BankAccount* myUsdAcc = user1.find_account("ACC-USD-001");
    if (myUsdAcc != nullptr) {
        std::cout << "\n[System] Account found! Making operations...\n";
        myUsdAcc->withdraw(250.0);
        myUsdAcc->deposit(50.0);
        myUsdAcc->print_history();
    } else {
        std::cout << "Account not found!\n";
    }

    return 0;
}
