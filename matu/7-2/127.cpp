#include <iostream>
using namespace std;

int main(){
    int j;
    for(j = 100; j<=200;j++)
    {
	    if(0 != j%3 && 0 != j%7)
            cout << j;
    }
    return 0;
}