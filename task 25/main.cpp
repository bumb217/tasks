#include <QCoreApplication>

#include "actions.h"
#include "paying.h"

int main()
{
    tax * first = new bankTax();
    tax * second = new countryTax();

    first->setMain(second);


    paying* firstP = new ordinary(1000);
    paying* secondP = new intrabank(1000);
  //  paying* thirdP = new national(1000);
    first->getTask(*firstP);
    cout << "\n\n";
    first->getTask(*secondP);
    cout << "\n\n";

/*
    tax * third = new countryTax();
    tax * yu = new bankTax();
    third->setMain(yu);
    third->getTask(*thirdP);

*/

    return 0;
}
