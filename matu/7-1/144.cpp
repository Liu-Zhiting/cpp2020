#include <iostream>
using namespace std;

void print(const char c, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << c;
    }
}

int main()
{
    int count;
    cin >> count;

    //check count
    if(count < 1 || count > 80 || 0 == count%2)
    {
        cout << "error";
        return 0;
    }

    //draw star
    for(int i = 0; i <= (count-1)/2;i++)
    {
        print(' ',i);
        print('*',count - 2*i);
        cout << endl;
    }
    return 0;
}