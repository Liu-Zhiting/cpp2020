#include <iostream>
#include "ClockAndDate.h"

using namespace std;

int Date::days(int year, int month)
{
    if(2 == month)
        return (0 == year%4) ? 29 : 28;

    switch(month)
       {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        default:
            return 31;
            break;
       }
}

void Date::NewDay()
{
    int max_day = this->days(year, month);
    day++;
    month += (day-1) / max_day;
    year += (month-1) / 12;
    day = ((day - 1) % max_day) + 1;
    month = ((month - 1) % 12) + 1;
}

class ClockWithDate: public Clock, public Date
{
    public:
        ClockWithDate(int h,int m,int s,int year , int month , int day): Clock(h,m,s),Date(year,month,day)
        {

        }

        void showTime()
        {
            cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
            this->display();
        }

        void run()
        {
            if(23 == hour && 59 == minute && 59 == second)
            {
                this->NewDay();
                hour = 0;
                minute = 0;
                second = 0;
                return;    
            }

            second = second+1;

		    if (second>59)
		    {
			    second =0;
			    minute+=1;
		    }
		    if (minute>59)
		    {
			    minute =0;
			    hour+=1;
		    }
		    if (hour>23)
		    {
			    hour =0;
		    }
        }

};

Clock* Clock::createClockWithDate(int h,int m,int s,int year,int month,int day){
	return new ClockWithDate(h,m,s,year,month,day);
}