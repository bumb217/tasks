#include <stdio.h>
#include "creditcard.h"

CreditCard::CreditCard() {
    balance = 0;
    state = "ok";
}

//-------------------------------------------------------------------- BANK OPERATIONS:

void CreditCard::setPassword(int pass) {
    password = pass;
}

void CreditCard::setBalance(int newBalance) {
    balance = newBalance;
}

void CreditCard::unblockCard() {
    state = "ok";
}

void CreditCard::blockCard() {
    state = "blocked";
}

int CreditCard::getPassword() {
    return password;
}

//------------------------------------------------------------------- CLIENT OPERATIONS:

void CreditCard::putMoney(int add_sum, int pass) {
    if (pass != password) {
        return;
    }
    if (state != "blocked") {
        balance += add_sum;
        return;
    }
    else {
        return;
    }
}

int CreditCard::getBalance(int pass) {
    if (pass != password) {
        return -1;
    }
    if (state != "blocked") {
        return balance;
    }
    else {
        return -1;
    }
}

void CreditCard::withdraw(int sum, int pass) {
    if (pass != password) {
        return;
    }
    if (sum > balance) {
        return;
    }
    
    else if (state != "blocked") {
        balance = balance - sum;
    }
    else {
    }
}
