#include <iostream>
using namespace std;

int main(){
    int i,j;
    for(i =0; i<=9;i++)
    {
        j = i*10 +6;
	    if(0 != j%3)
            continue;
	    cout << j;
    }
    return 0;
}