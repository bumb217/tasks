#ifndef CARETAKER_H
#define CARETAKER_H
#include <momento.h>
#include <originator.h>

class caretaker
{
private:
    vector<momento*>states;
public:
    void addMomento(momento* nMomento)
    {
        states.push_back(nMomento);
    }
    momento* getMomento(int index)
    {
        return states[index];
    }
};


#endif // CARETAKER_H
