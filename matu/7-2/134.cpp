#include<iostream>
#include<cstring>
using std::cout;

int SubStrNum(char * str,char * substr)
{
    //check str
    int len_A = strlen(str), len_B = strlen(substr);
    if(len_A < len_B)
    {
        cout << "match times=0";
        return 0;
    }
    
    //search substring
    int count = 0,i,j;
    for(i = 0; i < (len_A - len_B + 1); i++)
    {
        for(j = 0; j < len_B; j++)
            {if(str[i + j] != substr[j])
                {break;}}
        
        if(j >= len_B - 1 && str[i+len_B-1] == substr[len_B-1])
        {
            count++;
            i += len_B -1;
        }
    }
    cout << "match times=" << count;
    return count;

}