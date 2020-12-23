#include "Clock.h"
#include <iostream>
using namespace std;
Clock::Clock(int h,int m, int s){
    //valid input
    hour = (h >= 0 && h <= 23) ? h : 0;
    minute = (m >= 0 && m <= 59) ? m : 0;
    second = (s >= 0 && s <= 59) ? s : 0;

    Ahour = -1;
    Aminute = -1;
    Asecond = -1;
}
void Clock::SetAlarm(int h,int m, int s){
    Ahour = (h <= 23) ? h : -1;
    Aminute = (m <= 59) ? m : -1;
    Asecond = (s <= 59) ? s : -1;
}

void Clock::run(){
    //second add 1
    second++;

    //correct time
    minute += (second/60);
    second %= 60;
    hour += (minute/60);
    minute %= 60;
    hour %= 24;

    //ring alarm on time
    if(hour == Ahour && minute == Aminute && second == Asecond)
        cout << "Plink!plink!plink!..." << endl;
}

int main()
{
    Clock c(2,3,4);
    c.SetAlarm(2,3,5);
    c.run();

    return 0;
}

