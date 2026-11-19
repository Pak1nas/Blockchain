#include <iostream>
#include "user.h"
#include "hash.h"

using namespace std;

int main()
{

    cout<< "1. Programa pradeta"<<endl;

    cout<< "2. Hash testas: "<<generateHash("labas") << endl;

    cout << "3. Generuojami vartotojai" << endl;

    vector<User> users = generateUsers(1000);

    cout << "4. Vartotojai sugeneruoti" << endl;

    saveUsers(users);

    cout << "5. Vartotojai issaugoti" << endl;

    int64_t totalBalance = 0;

    for(const User& user : users)
    {
        totalBalance += user.balance;
    }

    cout << "Vartotoju skaicius: "<< users.size() << endl;

    cout << "Bendra lesu suma: "<< totalBalance << endl;
    return 0;
}
