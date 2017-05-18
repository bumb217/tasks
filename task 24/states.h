#ifndef STATES_H
#define STATES_H
#include <iostream>
#include <string>

using namespace std;

class state
{
public:
    virtual void showInfo() = 0;
};


class created:public state
{
public:
    void showInfo()
    {
        cout << "state = created\n";
    }
};

class considered:public state
{
public:
    void showInfo()
    {
        cout << "state = considered\n";
        cout << " 80 <= mark < 100 name is ok\n";
    }
};

class posponed:public state
{
public:
    void showInfo()
    {
        cout << "state = posponed\n";
        cout << "name is not ok\n";
    }
};

class rejected:public state
{
public:
    void showInfo()
    {
        cout << "state = rejected\n";
        cout << "mark < 50\n";

    }
};

class confirmed:public state
{
public:
    void showInfo()
    {
        cout << "state = confirmed\n";
        cout << "mark >=100 and name is ok\n";

    }
};

class withdraw:public state
{
public:
    void showInfo()
    {
        cout << "state = withdraw\n";
    }
};

#endif // STATES_H
