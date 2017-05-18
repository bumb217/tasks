#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include <momento.h>

class originator
{
protected:
    vector<int>state;
public:
    originator()
    {
        for (int i = 0; i < 9; i++)state.push_back(0);
    }
    momento* createMomento()
    {
        return new momento(state);
    }
    void setMomento(momento* curMomento)
    {
        state.clear();
        state = curMomento->getMomento();
    }
    bool makeMove(int index,int move)
    {
        if (state[index] == 0)
        {
            if (move % 2 == 0) state[index] = 1;
            else state[index] = -1;
            return true;
        }
        else return false;
    }

    void makeMachineMove(int move)
    {
        int nMove;
        if (move % 2 == 0) nMove = 1;
        else nMove = -1;
        if (haveToMove() == 0)
        {
            for (int  i = 0; i < 9; i ++)
            {
                if (state[i] == 0)
                {
                    state[i] = nMove;
                    if (haveToMove() == nMove) return;
                    state[i] = 0;
                }
            }
            for (int  i = 0; i < 9; i ++)
            {
                if (state[i] == 0)
                {
                    state[i] = nMove * (-1);
                    if (haveToMove() == nMove * (-1))
                    {
                        state[i] *= -1;
                        return;
                    }


                    state[i] = 0;
                }
            }
            if (state[4] == 0) {state[4] = nMove;return;}
            if (state[0] == 0) {state[0] = nMove;return;}
            if (state[2] == 0) {state[2] = nMove;return;}
            if (state[6] == 0) {state[6] = nMove;return;}
            if (state[8] == 0) {state[8] = nMove;return;}
            for (int  i = 0; i < 9; i ++)
            {
                if (state[i] == 0)
                {
                    state[i] = nMove;
                    return;
                }
            }
        }
    }

    char sign(int ch)
    {
        if (ch == 0) return ' ';
        if (ch == 1) return 'x';
        if (ch == -1) return 'o';
    }
    void show()
    {
        for (int i = 0; i < 9; i+=3)
        {
            cout << "\n------------\n";
           // cout << state[i] << " ";
            cout << sign(state[i]) << " | " << sign(state[i + 1]) << " | " << sign(state[i + 2]);
        }
        cout << "\n";
    }
    bool isFull()
    {
        for (int i = 0; i < 9;i++)
            if (state[i] == 0) return false;
        return true;
    }


    int haveToMove()
    {
        for (int i = 0; i < 9; i+=3)
        {
            if (state[i] == state[i+1] && state[i+1] == state[i+2] && state[i] != 0)
            {
                return state[i];
            }
        }
        for (int i = 0; i <3; i++)
        {
            if (state[i] == state[i+3] && state[i+6] == state[i+3] && state[i] != 0)
            {
                return state[i];
            }
        }
        if (state[0] == state[4] && state[4] == state[8] && state[4] != 0)
        {
            return state[0];
        }
        if (state[2] == state[4] && state[4] == state[6] && state[4] != 0)
        {
            return state[2];
        }
        return 0;

    }
};


#endif // ORIGINATOR_H
