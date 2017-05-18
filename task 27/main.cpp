#include <QCoreApplication>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class today
{
private:
    static today *instance;
    string myDay;
    static int nom;
    static string days[];
    today()
    {
        myDay = days[nom];
        cout << "create\n";
    }
public:
    static today* getInstance()
    {
        if (!instance)
        {
            instance = new today();
        }
        return instance;
    }
    virtual void showDay()
    {
        cout << myDay << "\n";
    }
    virtual void nextDay()
    {
        nom ++;
        nom %= 7;
        myDay = days[nom];
    }

};

today *today::instance = 0;
int today::nom = 0;
string today::days[] = {"Mn","Tu","We","Th","Fr","Sa","Su"};

int main()
{
    today::getInstance()->showDay();
    today::getInstance()->nextDay();
    today::getInstance()->showDay();
    today::getInstance()->nextDay();
    today::getInstance()->showDay();

    return 0;
}
