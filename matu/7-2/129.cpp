#include <iostream>
using namespace std;

int main()
{
    //init
    int year,month,day;
    cin >> year >> month;
    month = ((month - 1) % 12) + 1;
    cout << "days:";

    //figure
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            cout << 30;
            break;

        case 2:
            if(0 == year%4)
                cout << 29;
            else
                cout << 28;
            break;
        default:
            break;
    }
    return 0;
}
