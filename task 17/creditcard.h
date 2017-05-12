#ifndef creditcard_h
#define creditcard_h
#include <string>

using namespace std;

class CreditCard
{
    int balance;
    string state;
    int password;
public:
    
    CreditCard();
    
    //-------------------------------------------------------------------- BANK OPERATIONS:
    
    void setPassword(int pass);
    void setBalance(int newBalance);
    void unblockCard();
    void blockCard() ;
    int getPassword();
    
    //------------------------------------------------------------------- CLIENT OPERATIONS:
    
    void putMoney(int add_sum, int pass);
    int getBalance(int pass);
    void withdraw(int sum, int pass);
};


#endif /* creditcard_h */
