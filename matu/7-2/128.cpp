#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //init
    int steps = 1, n = 1, pos = -1;
    double pi = 1.0, tmp = 1.0;

    //figure pi
    while(tmp > 1e-8 || tmp < -1e-8)
    {
        n += 2;
        tmp = 1.0/n * pos;
        pos *= -1;
        pi += tmp;
        steps++;
    }
    pi *= 4;

    //output in certain formats
    cout << "steps=" << steps << " PI=";
    cout << fixed << setprecision(5) << pi;

}