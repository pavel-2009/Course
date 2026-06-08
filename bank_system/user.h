#pragma once

#include "bank_account.h"
#include <string>
#include <vector>


class User
{

private:
    std::string user_id;
    std::string name;
    std::vector<BankAccount> accounts;

public:
    User(const std::string& id, const std::string& username);

    ~User();

    void open_account(const std::string& acc_num, const std::string& currency, double initial_balance);

    BankAccount* find_account(const std::string& acc_num);

    std::string get_user_id() const;
    std::string get_name() const;
    void print_user_info() const;
};
