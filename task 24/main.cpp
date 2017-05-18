#include <QCoreApplication>
#include <application.h>

// Mark - баллы

int main()
{
    cout << "enter mark and name\n";
    int mark;
    string name;
    cin >> mark >> name;
    application* myApplication = new application(name,mark);
    myApplication->showState();
    myApplication->withDrawApplication();
    myApplication->showState();
    myApplication->~application();
    return 0;
}
