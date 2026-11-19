#include "transaction.h"
#include "hash.h"

#include <iostream>
#include <random>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <stdexcept>

using namespace std;

string serializeTransaction(const Transaction& tx){

    return tx.sender + "|" +
           tx.receiver + "|" +
           to_string(tx.amount) + "|" +
           to_string(tx.sequence);
}

string calculateTransactionID(const Transaction& tx){

    return generateHash(serializeTransaction(tx));
}

vector<Transaction> generateTransactions(
    const vector<User>& users, int count){

    if(users.size() < 2){
        throw runtime_error("Nepakanka vartotoju");
    }

    mt19937 gen(54321);

    uniform_int_distribution<int> userDist(
        0, users.size() - 1
    );

    uniform_int_distribution<int> amountDist(
        1, 10000
    );

    vector<Transaction> transactions;

    unordered_set<string> ids;

    for(int i = 0; i < count; i++){

        int senderIndex = userDist(gen);
        int receiverIndex = userDist(gen);

        while(senderIndex == receiverIndex){

            receiverIndex = userDist(gen);
        }

        Transaction tx;

        tx.sender = users[senderIndex].public_key;

        tx.receiver = users[receiverIndex].public_key;

        tx.amount = amountDist(gen);

        tx.sequence = i + 1;

        tx.transaction_id = calculateTransactionID(tx);

        if(!ids.insert(tx.transaction_id).second){

            throw runtime_error("Transakcijos ID kolizija");
        }

        transactions.push_back(tx);
    }

    return transactions;
}

void saveTransactions(
    const vector<Transaction>& transactions){

    filesystem::create_directories("data");

    ofstream failas("data/transactions.csv");

    if(!failas.is_open()){

        throw runtime_error(
            "Nepavyko sukurti transactions.csv"
        );
    }

    failas << "Sender,Receiver,Amount,Sequence,TransactionID\n";

    for(const Transaction& tx : transactions){

        failas << tx.sender << "," << tx.receiver << "," << tx.amount << "," << tx.sequence << "," << tx.transaction_id << "\n";
    }

    cout << "Transakcijos issaugotos" << endl;
}
