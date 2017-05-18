#ifndef TRAIN_H
#define TRAIN_H

#include <station.h>
#include <time.h>
#include <carriage.h>


class ticket;

class train
{
public:
    vector <pasCar*> pasCarriages;
    vector <serCar*> serCarriages;
    vector <station*> stations;
    int number;
    train()
    {

    }
    time leavingTime;
    time arrivalTime;
    void addSerCarriage(serCar* nCar)
    {
        serCarriages.push_back(nCar);

    }
    void addPasCarriage(pasCar* nCar)
    {
         pasCarriages.push_back(nCar);
    }
    void addStation(station* nStation)
    {
        bool haveStat = false;
        for(unsigned int i = 0; i < stations.size(); i++)
            if (stations[i]->name == nStation->name) haveStat = true;
        if(!haveStat)stations.push_back(nStation);
    }
    void showTicket(ticket* curTicket);

    void showTrain()
    {
        cout <<"number : " << number << " ";
        for (unsigned int i = 0; i <pasCarriages.size();i++)
        {
            cout << pasCarriages[i]->curTypePas << " free : " <<  pasCarriages[i]->numPlace - pasCarriages[i]->numberPassagers << " ";
            cout <<" price : " << pasCarriages[i]->priceForKilom;
            if (pasCarriages[i]->haveTv) cout << "have TV ";
             if (pasCarriages[i]->haveTelephone) cout << "have telephone ";
        }
        for (unsigned int i = 0; i <serCarriages.size();i++)
        {
            cout << serCarriages[i]->curTypeSer << " ";
            if (serCarriages[i]->haveTv) cout << "have TV ";
            if (serCarriages[i]->haveTelephone) cout << "have telephone ";
        }
        cout << "\n";
    }
};


#endif // TRAIN_H
