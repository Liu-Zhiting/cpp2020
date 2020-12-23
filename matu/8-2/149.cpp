#include<cstring>
#include "CString.h"

bool String::IsSubstring(const char *str)
{
    int i,j,sublen = strlen(str);

    for(i = 0; i < len - sublen; i++)
    {
        for(j = 0;j < sublen;j++)
            if(mystr[i+j] != str[j])
                break;
        if(j >= sublen -1 && mystr[i+sublen-1] == str[sublen-1])
            return true;
    }
    return false;
}

bool String::IsSubstring(const String &str)
{
    return IsSubstring(str.mystr);
}

int String::str2num()
{  
    int result = 0;
    for(int i = 0; i < len; i++)
    {
        if(mystr[i] >= '0' && mystr[i] <= '9')
        {
            result = result * 10 + mystr[i] - '0';
        }
    }
    return result;
}

void String::toUppercase()
{
    for(int i = 0; i < len; i++)
    {
        if(mystr[i] >= 'a' && mystr[i] <= 'z')
        {
            mystr[i] = mystr[i] - 'a' + 'A';
        }
    }
}