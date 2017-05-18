#include <QCoreApplication>
#include <ticket.h>

void createTrains()
{
    station* station1 = new station(coord(12,12)," 1 ");
    station* station2 = new station(coord(45,60)," 2 ");
    station* station3 = new station(coord(90,89)," 3 ");
    station* station4 = new station(coord(100,102)," 4 ");
    station* station5 = new station(coord(101,120)," 5 ");
    station* station6 = new station(coord(140,160)," 6 ");


    train* train1 = new train();
    train1->number = 1;
    train1->leavingTime = time(12,30);
    train1->arrivalTime = time(22,50);
    train1->addStation(station1);
    train1->addStation(station3);
    train1->addStation(station5);
    serCar* car1 = new serCar(cafe);
    car1->setTv();
    pasCar* car2 = new pasLyiCar();
    train1->addSerCarriage(car1);
    train1->addPasCarriage(car2);



    train* train2 = new train();
    train2->number = 2;
    train2->leavingTime = time(18,50);
    train2->arrivalTime = time(5,50);
    train2->addStation(station2);
    train2->addStation(station4);
    train2->addStation(station6);
    serCar* car3 = new serCar(restaurant);
    pasCar* car4 = new pasSitCar();
    car3->setTelephone();
    train2->addSerCarriage(car3);
    train2->addPasCarriage(car4);


    train1->showTrain();
    train2->showTrain();

    ticket myTicket;
    myTicket.date = time(1,4);
    myTicket.numberTrain = train1;
    myTicket.firstStation = *station1;
    myTicket.secondStation = *station3;
    myTicket.curTypePas  = lying;
    myTicket.getPrice();



    ticket myTicket2;
    myTicket2.date = time(1,4);
    myTicket2.numberTrain = train1;
    myTicket2.firstStation = *station1;
    myTicket2.secondStation = *station4;
    myTicket2.curTypePas  = lying;
    myTicket2.getPrice();

    ticket myTicket3;
    myTicket3.date = time(1,4);
    myTicket3.numberTrain = train2;
    myTicket3.firstStation = *station6;
    myTicket3.secondStation = *station4;
    myTicket3.curTypePas  = lying;
    myTicket3.getPrice();

}


int main()
{
    createTrains();
    return 0;
}
