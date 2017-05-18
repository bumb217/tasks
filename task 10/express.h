#ifndef EXPRESS_H
#define EXPRESS_H
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class express
{
public:
    virtual float findAns() = 0;
};


class sum:public express
{
private:
    express*  right;
    express*  left;
public:
    sum(express* nl,express* nr):right(nr),left(nl){}
    float findAns()
    {
        //cout <<(float)right->findAns() + (float)left->findAns();
        return (float)right->findAns() + (float)left->findAns();
    }
};


class number:public express
{
private:
    float ans;
public:
    number(float na):ans(na){}
    float findAns() {return ans;}
    void showAns(){cout << ans << "\n";}
};

class subtract:public express
{
private:
    express*  right;
    express*  left;
public:
    float findAns()
    {
        return (float)left->findAns() - right->findAns();
    }
    subtract(express* nl,express* nr):right(nr),left(nl){}
};



class multiply:public express
{
private:
    express*  right;
    express*  left;
public:
    multiply(express* nl,express* nr):right(nr),left(nl){}
    float findAns()
    {
        return (float)left->findAns() * right->findAns();
    }
};


class divide:public express
{
private:
    express*  right;
    express*  left;
public:
    divide(express* nl,express* nr):right(nr),left(nl){}
    float findAns()
    {
        if (fabs(right->findAns() - 0) > 0.003)
        return (float)left->findAns() / right->findAns();
        else{cout <<"div by 0"; return 0;}
    }
};



#endif // EXPRESS_H
