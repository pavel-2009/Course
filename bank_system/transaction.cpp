#include "transaction.h"
#include <string>
#include <vector>
#include <iomanip>


Transaction::Transaction(const std::string& id, TransactionType t, double amt, const std::string& time, BankAccount* from_acc, BankAccount* to_acc) 
    :transaction_id(id), type(t), amount(amt), timestamp(time), is_success(false), from_account(from_acc), to_account(to_acc)
    {

    };

Transaction::~Transaction() {
    
};

bool Transaction::execute() {
    if (type == TransactionType::TRANSFER) {
        if (from_account == nullptr || to_account == nullptr) {
            return false;
        };

        bool withdraw_ok = from_account->withdraw(amount);

        if (!withdraw_ok) {
            return false;
        };

        bool deposit_ok = to_account->deposit(amount);

        if (!deposit_ok) {
            return false;
        };

        is_success = true;
        return true;
    } else if (type == TransactionType::DEPOSIT) {
        bool deposit_ok = to_account->deposit(amount);

        if (!deposit_ok) {
            return false;
        };

        is_success = true;
        return true;
    } else if (type == TransactionType::WITHDRAW) {
        bool withdraw_ok = from_account->withdraw(amount);

        if (!withdraw_ok) {
            return true;
        };

        is_success = true;
        return true;
    }
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
    std::cout << "Amount: " << std::fixed << std::setprecision(2) << amount << std::endl;
    std::cout << "Timestamp: " << timestamp << std::endl;
    std::cout << "Status: " << (is_success ? "Success" : "Failed") << std::endl;
}
