#include "user.h"
#include "hash.h"

#include <iostream>
#include <random>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <stdexcept>

using namespace std;

vector<User> generateUsers(int count)
{

    mt19937 gen(12345);

    uniform_int_distribution<int> dist(100, 1000000);

    vector<User> users;

    unordered_set<string> keys;

    for(int i = 0; i < count; i++)
    {

        User user;

        user.name = "User" + to_string(i + 1);

        user.public_key = generateHash(user.name);

        user.balance = dist(gen);

        if(!keys.insert(user.public_key).second)
        {

            throw runtime_error("Public key kolizija");
        }

        users.push_back(user);
    }

    return users;
}

void saveUsers(const vector<User>& users)
{

    filesystem::create_directories("data");

    ofstream failas("data/users.csv");

    if(!failas.is_open())
    {

        throw runtime_error("Nepavyko sukurti users.csv");
    }

    failas << "Name,PublicKey,Balance\n";

    for(const User& user : users)
    {

        failas << user.name << "," << user.public_key << ","<< user.balance << "\n";
    }

    cout << "Vartotojai issaugoti" << endl;
}
