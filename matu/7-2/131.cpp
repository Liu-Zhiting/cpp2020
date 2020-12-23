#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

int cmpfunc(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int main()
{
    //init
    int a[10],b[10],tmp,a_tail = 0,b_tail = 0;
    memset(a, 0, sizeof(int));
    memset(b, 0, sizeof(int));

    //input
    for(int i = 0; i<10; i++)
    {
        cin >> tmp;
        if(tmp < 0)
            break;

        if(1 == tmp%2)
        {
            a[a_tail] = tmp;
            a_tail++;
        }
        else
        {
            b[b_tail] = tmp;
            b_tail++;
        }
    }

    //sort and output
    qsort(a,a_tail,sizeof(int),cmpfunc);
    qsort(b,b_tail,sizeof(int),cmpfunc);
    for(int i = 0; i < a_tail; i++)
        cout << a[i] << " ";
    for(int i = 0; i < b_tail; i++)
        cout << b[i] << " ";


}