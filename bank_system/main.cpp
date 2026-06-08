#include "bank_account.h"
#include "user.h"
#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>


int main() {
    User user1("USR-01", "Alex");
    User user2("USR-02", "John");

    user1.open_account("ACC-USD-01", "USD", 1000.0);
    user2.open_account("ACC-USD-02", "USD", 100.0);

    // Ищем счета в памяти
    BankAccount* alex_acc = user1.find_account("ACC-USD-01");
    BankAccount* john_acc = user2.find_account("ACC-USD-02");

    if (alex_acc && john_acc) {
        // Создаем транзакцию перевода 300 USD от Алекса к Джону
        Transaction tx("TX-9999", TransactionType::TRANSFER, 300.0, "2026-06-08 12:00", alex_acc, john_acc);
        
        std::cout << "Executing transfer...\n";
        if (tx.execute()) {
            std::cout << "Success!\n";
        } else {
            std::cout << "Failed!\n";
        }

        // Проверяем новые балансы и истории
        user1.print_user_info();
        user2.print_user_info();
        
        std::cout << "\n--- Detailed TX Info ---\n";
        tx.print();
    }
    return 0;
}
