#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <cstdint>

struct User {

    std::string name;
    std::string public_key;
    int64_t balance;

};

std::vector<User> generateUsers(int count);

void saveUsers(const std::vector<User>& users);

#endif
