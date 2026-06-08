#pragma once

#include "bank_account.h"
#include <string>
#include <iostream>

enum class TransactionType {
    DEPOSIT,
    WITHDRAW,
    TRANSFER,
};

class Transaction {

private:
    std::string transaction_id;
    TransactionType type;
    double amount;
    std::string timestamp;
    bool is_success;

    BankAccount* from_account;
    BankAccount* to_account;

public:
    Transaction(const std::string& id, TransactionType t, double amt, const std::string& time, BankAccount* from_acc, BankAccount* to_acc);

    ~Transaction();

    bool execute();

    std::string get_id() const;
    bool get_status() const;
    void print() const;
};