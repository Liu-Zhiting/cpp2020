#include <iostream>
using namespace std;

bool validDay(int year,int month,int day)
{
    if(day < 1 || day > 31)
        return false;

    switch(month)
    {
        case 2:
            return (0 == year%4) ? (day <= 29) : (day <= 28);
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
        default:
            return true;
    }
}

class Date{
public:
    Date(int y =1996,int m=1,int d=1){
        year=y;
        if(m <= 0 || m > 12)
        {
            cout<<"Invalid month!" <<endl;
            month=1;
        }
        else
            month=m;
        if(!validDay(y,m,d))
        {
            cout<<"Invalid day!" <<endl;
            day=1;
        }
        else
            day=d;
    };
    int days(int year,int month){
        if(month < 1 || month > 12 || year < 1)
            return 0;

        if(2 == month)
            return (0 == year%4) ? 29 : 28;

        switch(month)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                return 31;
        }
    };
    void NewDay()
    {
        int max_day = this->days(year, month);
        day++;
        month += (day-1) / max_day;
        year += (month-1) / 12;
        day = ((day - 1) % max_day) + 1;
        month = ((month - 1) % 12) + 1;
    };
    void display()
    {
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
private:
    int year; //年
    int month; //月
    int day;  // 日
};

int main() {
    Date d(1993,2,28);
    d.display();
    d.NewDay();
    d.display();

    return 0;
}
