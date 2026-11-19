#include <iostream>
#include "user.h"
#include "hash.h"
#include "transaction.h"

using namespace std;

int main(){

    vector<User> users = generateUsers(1000);

    saveUsers(users);

    int64_t totalBalance = 0;

    for(const User& user : users){

        totalBalance += user.balance;
    }

    cout << "Vartotoju skaicius: " << users.size() << endl;

    cout << "Pradine lesu suma: " << totalBalance << endl;

    vector<Transaction> transactions =
        generateTransactions(users, 10000);

    saveTransactions(transactions);

    cout << "Transakciju skaicius: " << transactions.size() << endl;

    cout << "\nPirmoji transakcija:\n";

    cout << "Siuntejas: " << transactions[0].sender << endl;

    cout << "Gavejas: " << transactions[0].receiver << endl;

    cout << "Suma: " << transactions[0].amount << endl;

    cout << "Sequence: " << transactions[0].sequence << endl;

    cout << "Transaction ID: " << transactions[0].transaction_id << endl;

    return 0;
}
