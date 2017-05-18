#ifndef MOMENTO_H
#define MOMENTO_H

#include <iostream>
#include <vector>
using namespace std;


class momento
{
private:
    vector<int> state;
   // friend class originator;
public:
    void setMomento(vector <int> nState)
    {
        state.clear();
        for(int i = 0; i < nState.size(); i++)
            state.push_back(nState[i]);
    }
    momento(vector <int> nState)
    {
        state.clear();
        for(int i = 0; i < nState.size(); i++)
            state.push_back(nState[i]);
    }
    vector<int> getMomento()
    {
        return state;
    }
};


#endif // MOMENTO_H
