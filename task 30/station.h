#ifndef STATION_H
#define STATION_H
#include <iostream>
#include <vector>

using namespace std;

class coord
{
public:
    int first;
    int second;
    coord(int f,int s){first = f;second = s;}
    coord(){first = 0; second = 0;}
};

class station
{
public:
    coord stCoord;
    string name;
    station(){}
    station(coord nCoord, string nName)
    {
        stCoord = nCoord;
        name = nName;
    }
};


#endif // STATION_H
