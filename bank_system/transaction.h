#pragma once

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
    std::string timestamp; // Для простоты пока оставим строкой
    bool is_success;

public:
    Transaction(const std::string& id, TransactionType t, double amt, const std::string& time);

    ~Transaction();

    void execute();

    std::string get_id() const;
    bool get_status() const;
    void print() const;
};