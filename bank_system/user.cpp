#include "user.h"
#include "bank_account.h"
#include <string>
#include <vector>


User::User(const std::string& id, const std::string& username)
    : user_id(id), name(username) {

    };

User::~User() {

};

void User::open_account(const std::string& acc_num, const std::string& currency, double initial_balance) {
    accounts.emplace_back(std::make_unique<BankAccount>(acc_num, currency, initial_balance));
};

BankAccount* User::find_account(const std::string& acc_num) {
    for (auto& acc: accounts) {
        if (acc->get_account_number() == acc_num) {
            return acc.get();
        };

    };
    
    return nullptr;
};

std::string User::get_name() const {
    return name;
};

std::string User::get_user_id() const {
    return user_id;
};

void User::print_user_info() const {
    std::cout << "===============================" << std::endl;
    std::cout << "User ID: " << user_id << ", Name: " << name << std::endl;
    std::cout << "Accounts: " << std::endl;

    for (const auto& acc: accounts) {
        std::cout << "  - Account Number: " << acc->get_account_number() 
                  << ", Currency: " << acc->get_currency() 
                  << ", Balance: " << acc->get_balance() << std::endl;
    };  
    std::cout << "===============================" << std::endl;
}
