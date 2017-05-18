#ifndef TIME_H
#define TIME_H

class time
{
public:
    int hours;
    int minutes;
    time(){}
    time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
};

#endif // TIME_H
