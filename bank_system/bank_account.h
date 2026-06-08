#pragma once

#include <iostream>
#include <string>
#include <vector>


class BankAccount
{

private:
    std::string account_number;
    std::string currency;
    double balance;
    std::vector<std::string> transaction_history;

public:
    BankAccount(const std::string& acc_num, const std::string& curr, double initial_balance);

    ~BankAccount();

    bool deposit(double amount);
    bool withdraw(double amount);

    double get_balance() const;
    std::string get_account_number() const;
    std::string get_currency() const;
    void print_history() const;
};

