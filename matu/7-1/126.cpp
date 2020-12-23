#include<iostream>
using namespace std;

unsigned long jc(int n)
{
    unsigned long result = 1;
    for(unsigned long i = 1; i <= n; ++i)
    {
        result = result * i;   
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    if(n >= 13)   //13! > max of unsigned long, use 12!
    {
        cout << "12!=479001600";
        return 0;
    }

    cout << n << "!=" << jc(n);
    return 0;
}
