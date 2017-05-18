#include <QCoreApplication>
#include <express.h>
#include <calculate.cpp>

using namespace std;

int main()
{
    string expression;
    cin >> expression;

    express* answer = calculate(expression);
    cout << answer->findAns();

    return 0;
}
