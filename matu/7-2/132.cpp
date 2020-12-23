#include<cstdio>
#include<cstring>
const int MAX = 100;

int main()
{
    //init
    char a[MAX], b[MAX];
    int i = 0;
    memset(a, 0, sizeof(char) * MAX);
    memset(b, 0, sizeof(char) * MAX);
    scanf("%s",&a);

    //copy
    while(a[i] != '\0')
    {
        b[i] = a[i];
        i++;
    }
    b[i++] = '\\';
    b[i++] = '0';
    b[i++] = '0';

    //output
    printf("%s",b);

}