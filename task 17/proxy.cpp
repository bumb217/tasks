#include <stdio.h>
#include "proxy.h"

CreditCardProxy::CreditCardProxy(CreditCard* card) {
    number_of_balance_op = 0;
    number_of_withdraws = 0;
    number_of_puts = 0;
    
    realCard = card;
}
void CreditCardProxy::putMoney(int add_sum, int pass)
{
    number_of_puts++;
    realCard->putMoney(add_sum, pass);
}

int CreditCardProxy::getBalance(int pass){
    number_of_balance_op++;
    return realCard->getBalance(pass);
}

void CreditCardProxy::withdraw(int sum, int pass) {
    number_of_withdraws++;
    realCard->withdraw(sum, pass);
}
