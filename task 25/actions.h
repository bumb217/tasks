#ifndef ACTIONS_H
#define ACTIONS_H


#include "paying.h"

class tax
{
protected:
    tax* mainAction;
public:
    void setMain(tax* _mainAction){mainAction = _mainAction;}
    virtual void getTask(paying & _paying) = 0;
};


class bankTax:public tax
{
    void getTask(paying & _paying)
    {
        if (_paying.getRang() < 3)
        {
            cout << " bank ";
             _paying.madePayment();
        }
        else if (mainAction)
        {
            cout <<" country ";
            mainAction->getTask(_paying);
        }
        else cout << "no tax";
    }
};

class countryTax:public tax
{
     void getTask(paying & _paying)
     {
        if (_paying.getRang() < 2)
        {
            cout <<" country ";

            _paying.madePayment();
        }
        else if (mainAction)
        {
            cout << " bank ";
            mainAction->getTask(_paying);
        }
        else cout << "no tax";
    }
};



#endif // ACTIONS_H
