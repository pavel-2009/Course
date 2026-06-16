#include "bank_account.h"
#include <iostream>
#include <string>
#include <vector>


BankAccount::BankAccount(const std::string& acc_num, const std::string& curr, double initial_balance)
: account_number(acc_num), currency(curr), balance(initial_balance)
{
    if (initial_balance <= 0) {
        return;
    };

    std::string transaction = "[INFO] Account " + account_number + " opened. Initial balance: " + std::to_string(balance) + " " + currency + ".";

    transaction_history.push_back(std::make_unique<std::string>(transaction));
};

BankAccount::~BankAccount() {
    
};

bool BankAccount::deposit(double amount) {
    if (amount <= 0) {
        return false; 
    }

    balance += amount;

    std::string logMessage = "[DEPOSIT] +" + std::to_string(amount) + " " + currency 
                             + ". New balance: " + std::to_string(balance) + " " + currency;

    transaction_history.push_back(std::make_unique<std::string>(logMessage));

    return true;
};

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || balance < amount) {
        return false; 
    };

    balance -= amount;

    std::string logMessage = "[WITHDRAW] -" + std::to_string(amount) + " " + currency 
                             + ". New balance: " + std::to_string(balance) + " " + currency;
    transaction_history.push_back(std::make_unique<std::string>(logMessage));

    return true;
};

// Thread-safe versions of deposit and withdraw methods
bool BankAccount::deposit_safe(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    return deposit(amount);
};

bool BankAccount::withdraw_safe(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    return withdraw(amount);
};

double BankAccount::get_balance() const {
    return balance;
}

std::string BankAccount::get_account_number() const {
    return account_number;
}

std::string BankAccount::get_currency() const {
    return currency;
}

void BankAccount::print_history() const {
    std::cout << "\n=== Transaction History for Account: " << account_number << " ===\n";

    for (const auto& log: transaction_history) {
        std::cout << *log << std::endl;
    };

    std::cout << "========================================================\n";
};
