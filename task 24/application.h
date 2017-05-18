#ifndef APPLICATION_H
#define APPLICATION_H
#include <states.h>

class application
{
private:
    int mark;
    state* curState;
    string name;

public:
    application(string nName,int nMark)
    {
        mark = nMark;
        name = nName;
        findState();
    }
    ~application(){}
    void showState()
    {
        curState->showInfo();
    }
    void withDrawApplication()
    {
        curState = new withdraw();
    }
    
private:
    bool goodName()
    {
        //cout << name.size() << "\n";
        for (unsigned int i = 0; i < name.size(); i++)
        {
            if (name[i] - 'A' < 0) return false;
        }
        //cout << "+";
        return true;
    }
    void findState()
    {
        if (mark < 50) {curState = new rejected();return;}
        if (!goodName()) {curState = new posponed();return;}
        if (mark >= 100 ) {curState = new confirmed();return;}
        if (mark > 80) {curState = new considered();return;}
        curState = new created();
    }
};

#endif // APPLICATION_H
