#ifndef PAYING_H
#define PAYING_H

#include "iostream"
using namespace std;

class paying
{
public:
    int money;
    int tax;
public:
    virtual int showTax() = 0;
    virtual int getRang() = 0;
    virtual void madePayment() = 0;
};


class ordinary : public paying
{
public:
    ordinary(int _money){money = _money;tax = money * 0.05;}
    int getRang(){return 0;}
    int showTax()
    {
        return tax;
    }
    void madePayment()
    {
        money -= tax;
        cout <<"tax = " << tax << " money = " << money  << "\n";
    }
};

class preferential : public paying
{
public:

    preferential(int _money){money = _money;tax = money * 0.025;}
    int getRang(){return 1;}
    int showTax()
    {
        return tax;
    }
    void madePayment()
    {
        money -= tax;
        cout <<"tax = " << tax << " money = " << money  << "\n";
    }
};

class national : public paying
{
public:

    national(int _money){money = _money;tax = money * 0.02;}
    int getRang(){return 2;}
    int showTax()
    {
        return tax;
    }
    void madePayment()
    {
        money -= tax;
        cout <<"tax = " << tax << " money = " << money  << "\n";
    }
};

class intrabank : public paying
{
public:
    intrabank(int _money){money = _money;tax = 0;}
    int getRang(){return 3;}
    int showTax()
    {
        return tax;
    }
    void madePayment()
    {
        money -= tax;
        cout <<"tax = " << tax << " money = " << money  << "\n";
    }
};


#endif // PAYING_H
