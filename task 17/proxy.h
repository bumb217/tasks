#ifndef proxy_h
#define proxy_h

#include "creditcard.h"

using namespace std;

class CreditCardOperation //only operations that client can do with a credit card
{
public:
    virtual int getBalance(int pass) = 0;
    virtual void putMoney(int add_sum, int pass) = 0;
    virtual void withdraw(int sum, int pass) = 0;
    
    int number_of_balance_op;
    int number_of_withdraws;
    int number_of_puts;
};


class CreditCardProxy : public CreditCardOperation
{
    CreditCard* realCard;
public:
    CreditCardProxy(CreditCard* card);
    void putMoney(int add_sum, int pass);
    int getBalance(int pass);
    void withdraw(int sum, int pass);
};


#endif /* proxy_h */
