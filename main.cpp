#include <iostream>
#include "user.h"

using namespace std;

int main(){

    vector<User> users = generateUsers(1000);

    saveUsers(users);

    int64_t totalBalance = 0;

    for(const User& user : users){

        totalBalance += user.balance;
    }

    cout << "Vartotoju skaicius: " << users.size() << endl;

    cout << "Bendra lesu suma: " << totalBalance << endl;

    cout << "\nPirmi 5 vartotojai:\n";

    for(int i = 0; i < 5; i++){

        cout << "Vardas: "<< users[i].name << endl;

        cout << "Public key: "<< users[i].public_key << endl;

        cout << "Balansas: "<< users[i].balance << endl;

        cout << "-----------------------" << endl;
    }

    return 0;
}

