#include <iostream>

#include "creditcard.h"
#include "proxy.h"


#define CATCH_CONFIG_MAIN
#include "catch.h"

TEST_CASE("Simple card")
{
    CreditCard realCreditCard; //create credit card
    realCreditCard.setBalance(3000);
    realCreditCard.setPassword(1234);
    
    REQUIRE(realCreditCard.getBalance(1234) == 3000);
}

TEST_CASE("Proxy - withdraw")
{
    CreditCard card; //create credit card
    card.setBalance(3000);
    card.setPassword(1234);
    
    CreditCardOperation* proxy = new CreditCardProxy(&card); //creating a proxy for client
    
    REQUIRE(proxy->getBalance(1234) == 3000);
    
    proxy->withdraw(20, 1234);
    REQUIRE( proxy->getBalance(1234)== 2980);
    proxy->withdraw(20, 12); //wrong password -> balance stays the same
    REQUIRE( proxy->getBalance(1234)== 2980);
    
    REQUIRE(proxy->number_of_balance_op == 3);
    REQUIRE(proxy->number_of_puts== 0);
    REQUIRE(proxy->number_of_withdraws == 2);
}


TEST_CASE("Proxy - put money")
{
    CreditCard card; //create credit card
    card.setBalance(3000);
    card.setPassword(1234);
    
    CreditCardOperation* proxy = new CreditCardProxy(&card); //creating a proxy for client
    
    proxy->putMoney(1000, 1234);
    REQUIRE( proxy->getBalance(1234)== 4000);
    proxy->putMoney(1000, 12); //wrong password -> balance stays the same
    REQUIRE( proxy->getBalance(1234)== 4000);
    
    REQUIRE(proxy->number_of_balance_op == 2);
    REQUIRE(proxy->number_of_puts== 2);
    REQUIRE(proxy->number_of_withdraws == 0);
}
