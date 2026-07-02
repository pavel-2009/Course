#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>


class User : public std::enable_shared_from_this<User> {
    private:
        std::string name;
        std::vector<std::weak_ptr<User>> friends;

    public:
        User(const std::string& userName);
        ~User();

        std::string get_name() const;
        void add_friend(std::shared_ptr<User> newFriend);
        void print_friends() const;
};
