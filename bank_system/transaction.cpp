#include "transaction.h"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

Transaction::Transaction(const std::string& id, TransactionType t, double amt, const std::string& time, BankAccount* from_acc, BankAccount* to_acc) 
    : transaction_id(id), type(t), amount(amt), timestamp(time), is_success(false), from_account(from_acc), to_account(to_acc) 
{
}

Transaction::~Transaction() {
}

bool Transaction::execute() {
    if (type == TransactionType::TRANSFER) {
        // Защита от нулевых указателей
        if (from_account == nullptr || to_account == nullptr) return false;

        // Важно: если списание прошло, а зачисление вдруг упало (например, счет заморожен),
        // нужно вернуть деньги обратно! (Обеспечиваем атомарность транзакции)
        if (from_account->withdraw(amount)) {
            if (to_account->deposit(amount)) {
                is_success = true;
                return true;
            } else {
                // Откат (Rollback), если зачисление не удалось
                from_account->deposit(amount); 
            }
        }
        return false;
    } 
    else if (type == TransactionType::DEPOSIT) {
        if (to_account == nullptr) return false;
        
        if (to_account->deposit(amount)) {
            is_success = true;
            return true; // Исправлено на true
        }
        return false;
    } 
    else if (type == TransactionType::WITHDRAW) {
        if (from_account == nullptr) return false;
        
        if (from_account->withdraw(amount)) {
            is_success = true;
            return true;
        }
        return false;
    }
    
    return false; // На случай, если enum расширится, а логику забудут написать
}

std::string Transaction::get_id() const {
    return transaction_id;
}

bool Transaction::get_status() const {
    return is_success;
}

void Transaction::print() const {
    std::cout << "Transaction ID: " << transaction_id << std::endl;
    
    std::cout << "Type: ";
    if (type == TransactionType::DEPOSIT) std::cout << "Deposit";
    else if (type == TransactionType::WITHDRAW) std::cout << "Withdrawal";
    else if (type == TransactionType::TRANSFER) {
        std::cout << "Transfer (" << from_account->get_account_number() 
                  << " -> " << to_account->get_account_number() << ")";
    }
    std::cout << std::endl;

    std::cout << "Amount: " << std::fixed << std::setprecision(2) << amount << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Status: " << (is_success ? "Success" : "Failed") << std::endl;
}
