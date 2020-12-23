#include <iostream>
using namespace std;

class Date{
public:
	Date(int y=1996,int m=1,int d=1){
		day = d;
		month = m;
		year = y;
		if (m>12 || m<1)
		{
			month=1;
		}
		if (d>days(y,m))
		{
			cout<<"Invalid day!"<<endl;
			day=1;
		}
	};
	int days(int y,int m)
    {
        if (2 == m)
            return (y % 4 == 0) ? 29 : 28;

        switch(m)
        {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default: return 31;
        }
    }

    friend ostream& operator <<(ostream & out, Date & dt)
    {
        out << dt.year << "-" << dt.month << "-"<< dt.day << endl;
        return out;
    }

	void display(){
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
private:
	int year;
	int month;
	int day;
};

int main(){
     int y,m,d;
	 cin>>y>>m>>d;
	 Date dt(y,m,d);
	 cout<<dt;
	 return 0;
}