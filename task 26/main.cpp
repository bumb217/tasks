#include <QCoreApplication>
#include <momento.h>
#include <caretaker.h>
#include <originator.h>


void game(int player)
{
    originator* org = new originator;
    caretaker* care = new caretaker;
    care->addMomento(org->createMomento());
    int numberState = 0;
    int numberMove = 0;
    if (player == 2)
    {
        org->makeMachineMove(numberMove++);
        org->show();
        care->addMomento(org->createMomento());
        numberState++;
    }

    org->show();
    int haveToPlay = -100;
    while (haveToPlay != 0)
    {

       int move = -10;
       while(move > 10 || move < -1)
       {
           cout << "enter place (0 to take move back)\n";
           cin >> move;
       }
       if (move == 0)
       {
           if(numberState > 0) org->setMomento(care->getMomento(numberState - 1));
           //if(numberState > 0) {numberState--;}
       }
       else
       {
           if (org->makeMove(move - 1,numberMove))
           {
               numberMove++;
             //  org->show();
               org->makeMachineMove(numberMove++);
               org->show();
               care->addMomento(org->createMomento());
               numberState++;
           }
       }
    if (player == 1)
    {

       haveToPlay = org->haveToMove();
       if (haveToPlay == 1){ cout << "you win!\n";return;}
       if (haveToPlay == -1){ cout << "you lost!\n";return;}
       if(org->isFull()) {cout <<"draw\n";return;}
       if (haveToPlay == 0)haveToPlay = 1;
    }
    else
    {

       haveToPlay = org->haveToMove();
       if (haveToPlay == -1){ cout << "you win!\n";return;}
       if (haveToPlay == 1){ cout << "you lost!\n";return;}
       if(org->isFull()) {cout <<"draw\n";return;}
       if (haveToPlay == 0)haveToPlay = 1;
    }

    }
}

int main()
{
    int player = 0;
    while (player != 1 && player != 2)
    {
        cout << "enter player 1/2 : \n";
        cin >> player;
    }
    game(player);
    return 0;
}
