#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <cstdint>
#include "user.h"

struct Transaction {

    std::string sender;
    std::string receiver;
    int64_t amount;
    uint64_t sequence;
    std::string transaction_id;

};

std::string serializeTransaction(const Transaction& tx);

std::string calculateTransactionID(const Transaction& tx);

std::vector<Transaction> generateTransactions(
    const std::vector<User>& users, int count
);

void saveTransactions(const std::vector<Transaction>& transactions);

#endif
