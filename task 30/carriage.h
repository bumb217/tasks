#ifndef CARRIAGE_H
#define CARRIAGE_H


enum typeCarr{passenger,service};

class carriage
{
public:
    carriage()
    {
        haveTelephone = false;
        haveTv = false;
    }
    bool haveTv;
    bool haveTelephone;
    typeCarr curType;
    void setTv(){haveTv = true;}
    void setTelephone(){haveTelephone = true;}
};

enum typePas{sitting,lying,lyingBed};

class pasCar:public carriage
{
public:
    typePas curTypePas;
    int numPlace;
    int priceForKilom;
    int numberPassagers;
    pasCar()
    {
        curType = passenger;
    }
    bool haveTicket()
    {
        if (numberPassagers < numPlace)
        {
            return true;
        }
        return false;
    }
    void getTicket()
    {
        if (numberPassagers < numPlace)
        {
            numberPassagers++;
        }
    }
};

class pasSitCar:public pasCar
{
public:
    pasSitCar()
    {
        numPlace = 5;
        priceForKilom = 10;
        curTypePas = sitting;
        curType = passenger;
    }
};


class pasLyiCar:public pasCar
{
public:
    pasLyiCar()
    {
        numPlace = 3;
        priceForKilom = 20;
        curTypePas = lying;
        curType = passenger;
    }
};

class pasLyiBedCar:public pasCar
{
public:
    pasLyiBedCar()
    {
        numPlace = 2;
        priceForKilom = 35;
        curTypePas = lyingBed;
        curType = passenger;
    }
};


enum typeSer{mail,restaurant,cafe};

class serCar:public carriage
{
public:
    typeSer curTypeSer;
    serCar(typeSer curr){curType = service;curTypeSer  = curr;}
};
#endif // CARRIAGE_H
