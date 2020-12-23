#include <iostream>
#include "Clock.h"

using namespace std;

class NewClock : public Clock
{
    public:
        NewClock(int h,int m,int s) : Clock(h,m,s)
        {

        }

        void showTime()
        {
            //init
            int h = getHour(),m = getMinute(),s = getSecond();
            char AorP = (h <= 11) ? 'A':'P';
            int hourIn12 = (h >= 12) ? (h-12) : h;

            //print
            cout << "Now:" << hourIn12 << ":" << m << ":" << s;
            cout << AorP << 'M' << endl;
        }
};

Clock* Clock::createNewClock(int h,int m,int s){
	return new NewClock(h,m,s);
}