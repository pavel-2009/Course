#include "user.h"


User::User(const std::string& username) : name(username) {
    std::cout << "[CONSTRUCTOR] User " << name << " created.\n";
};

User::~User() {
    std::cout << "[DESTRUCTOR] User " << name << " destroyed.\n";
}

std::string User::get_name() const {
    return name;
}

void User::add_friend(std::shared_ptr<User> new_friend) {
    if (!new_friend) return;

    for (const auto& edge: friends) {
        if (auto f = edge.lock()) {
            if (f == new_friend) return;
        }
    }

    friends.push_back(new_friend);

    new_friend->friends.push_back(shared_from_this());
}

void User::print_friends() const {
    std::cout << "Friends of " << name << ": ";
    bool first = true;
    for (const auto& edge : friends) {
        if (auto friend_ptr = edge.lock()) {
            if (!first) std::cout << ", ";
            std::cout << friend_ptr->get_name();
            first = false;
        }
    }
    if (first) std::cout << "None";
    std::cout << "\n";
}
