#ifndef TICKET_H
#define TICKET_H
#include <cmath>
#include <train.h>

class  ticket
{
public:
    station firstStation;
    station secondStation;
    train* numberTrain;
    time date;
    typePas curTypePas;
    bool haveRestourant;
    bool haveTv;
    bool haveTelephone;
    bool haveCafe;
    bool haveBed;
    void getPrice()
    {
        numberTrain->showTicket(this);
    }
    void buy();
    ticket()
    {
        haveRestourant = false;
        haveTv = false;
        haveTelephone= false;
        haveCafe = false;
        haveBed = false;
        price = 0;
    }
    void setPrice(int p)
    {
        price = p;
    }
private:
    int price;
};


int dis(station f, station s)
{
    int ans = (f.stCoord.first - s.stCoord.first)*(f.stCoord.first - s.stCoord.first);
    ans += (f.stCoord.second - s.stCoord.second) * (f.stCoord.second - s.stCoord.second);
    ans = (int) sqrt((double)ans);
    return ans;
}


void train::showTicket(ticket *curTicket)
{
    if (curTicket->firstStation.name == curTicket->secondStation.name)
    {
        cout << "same Stations\n";
        curTicket->setPrice(-1);
        return;
    }
    bool haveFirst = false;
    bool haveSecond = false;
    for (unsigned int i = 0; i < stations.size(); i++)
    {
        if(stations[i]->name == curTicket->firstStation.name) haveFirst = true;
        if(stations[i]->name == curTicket->secondStation.name) haveSecond = true;
    }
    if (!haveFirst || !haveSecond)
    {
        cout << "We don't have such station!\n";
        curTicket->setPrice(-1);
        return;
    }

    int price = 0;
    for (unsigned int i = 0; i < pasCarriages.size(); i++)
    {
       if (pasCarriages[i]->curTypePas == curTicket->curTypePas)
       {
            if(pasCarriages[i]->haveTicket())
            {
                price = pasCarriages[i]->priceForKilom * dis(curTicket->firstStation,curTicket->secondStation);
                if (pasCarriages[i]->haveTelephone){cout << "with telephone \n"; price += 5;}
                if (pasCarriages[i]->haveTv){cout << " with TV \n"; price += 10;}
                if (pasCarriages[i]->curTypePas == lyingBed)
                    if (curTicket->haveBed == true)
                    {
                        cout <<" with bed \n";
                        price += 2;
                    }
            }
            for (unsigned int i = 0; i < serCarriages.size();i++)
            {
                if(serCarriages[i]->curTypeSer == cafe)
                {
                    cout << "with cafe\n";
                    price += 1;
                }
                if(serCarriages[i]->curTypeSer == restaurant)
                {
                    cout << "with cafe\n";
                    price += 2;
                }
            }
       }
       if  (price == 0) cout << "no ticket with such requirment!\n";
       cout << price << "\n";
    }
}

#endif // TICKET_H
