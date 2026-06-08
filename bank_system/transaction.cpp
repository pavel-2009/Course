#include "transaction.h"
#include <string>
#include <vector>


Transaction::Transaction(const std::string& id, TransactionType t, double amt, const std::string& time) 
    :transaction_id(id), type(t), amount(amt), timestamp(time), is_success(false)
    {

    };

Transaction::~Transaction() {
    
};

void Transaction::execute() {
    // Здесь будет логика выполнения транзакции
    // Для простоты пока просто пометим как успешную
    is_success = true;
};

std::string Transaction::get_id() const {
    return transaction_id;
};

bool Transaction::get_status() const {
    return is_success;
};

void Transaction::print() const {
    std::cout << "Transaction ID: " << transaction_id << std::endl;
    std::cout << "Type: " << (type == TransactionType::DEPOSIT ? "Deposit" : "Withdrawal") << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Status: " << (is_success ? "Success" : "Failed") << std::endl;
}
