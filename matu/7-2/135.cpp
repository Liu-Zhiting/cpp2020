#include <iostream>
#include <cstring>

using namespace std;

//global const
const int MAX_N = 52;

//struct
typedef struct
{
    char data[MAX_N];
} BigInt;

int cmpBigInt(BigInt left, BigInt right)
{
    //init
    int len_L = strlen(left.data),len_R = strlen(right.data);

    //judge by length
    if(len_L != len_R)
        return len_L - len_R;

    //compare every bit
    for (int i = 0; i < len_L; ++i)
    {
        if(left.data[i] == right.data[i])
            continue;
        return left.data[i] - right.data[i];
    }

    return 0;
}

BigInt bigMinus(BigInt left, BigInt right, int cmp)
{
    //check if equal
    if(0 == cmp)
    {
        BigInt result;
        memset(&result,0, sizeof(BigInt));
        result.data[0] = '0';
        result.data[1] = '\0';
        return result;
    }

    //init
    BigInt result, * pLeft = NULL, * pRight = NULL;
    memset(&result,0, sizeof(BigInt));
    char tmp = 0;
    int a,b;
    int len_L = strlen(left.data),len_R = strlen(right.data);
    int len = max(len_L,len_R);
    result.data[len] = '\0';

    //set bigger to left
    pLeft = (cmp < 0) ? &(right) : &(left);
    pRight = (cmp < 0) ? &(left) : &(right);

    //minus
    for(int i = 1; i <= max(len_L,len_R); i++)
    {
        a = (len_L - i >= 0) ? (pLeft->data[len_L - i] - '0') : 0;
        b = (len_R - i >= 0) ? (pRight->data[len_R - i] - '0') : 0;
        tmp = a - b;
        result.data[len-i] += tmp;

        //borrow bit
        if(result.data[len-i] < 0)
        {
            result.data[len-i-1] -= 1;
            result.data[len-i] += 10;
        }
        result.data[len-i] += '0';
    }

    return result;
}

int main()
{
    BigInt a, b,c;
    cin >> a.data >> b.data;

    int cmp = cmpBigInt(a, b);
    if(0 == cmp)
    {
        cout << "0";
        return 0;
    }

    c = bigMinus(a,b,cmp);
    char opt = (cmp > 0) ? '+' : '-';
    cout << opt << c.data;
    return 0;

}

