#include "CString.h"
#include <cstring>
#include <cstdlib>

int EditString::IsSubString(int start, const char *str)
{
    //init
    int sub_len = strlen(str);
    int i,j;
    if(this->len < sub_len)
        return -1;   //substring longer than string literal

    //search substring
    for(i = start; i < (len-start - sub_len + 1); i++)
    {
        for(j = 0; j < sub_len; j++)
            if(mystr[i + j] != str[j])
                break;
        
        if(j >= sub_len - 1 && mystr[i+sub_len-1] == str[sub_len-1])
        {
            return i;
        }
    }
    return -1;
    
}

void EditString::EditChar(char s, char d)
{
    for(int i = 0; i < len; i++)
    {
        if(s == mystr[i])
            mystr[i] = d;
    }
}

void EditString::EditSub(char * subs,char *subd)
{
    //init
    int subs_len = strlen(subs),subd_len = strlen(subd);
    if(len < subs_len)
        return;
    int tmp_len = abs(subs_len - subd_len) * len + len + 1;   // +1 to avoid overflow.
    int tmp_tail = 0;
    char * tmp = new char[tmp_len];
    int i,j;

    //search substring
    for(i = 0; i < (len - subs_len + 1); i++)
    {
        for(j = 0; j < subs_len; j++)
            if(subs[j] != mystr[i + j])  //mystr[i+j] is very important!!
                break;
        
        //if subs is found in string, copy subd to tmp
        if(j >= subs_len - 1 && mystr[i+subs_len-1] == subs[subs_len-1])
        {
            for(int k = 0;k<subd_len; k++)
                tmp[tmp_tail++] = subd[k];
            i = i + subs_len - 1;
            continue;
        }

        //if not, copy mystr to tmp
        tmp[tmp_tail++] = mystr[i];
    }

    //copy the rest of mystr to tmp
    for(;i<len;i++)   //DO NOT initialize i with len - subs_len + 1, otherwise i might rollback
        tmp[tmp_tail++] = mystr[i];

    //substitute mystr with tmp
    tmp[tmp_tail] = '\0';
    delete [] mystr;
    mystr = tmp;
    len = tmp_tail;
}

void EditString::DeleteChar(char ch)
{
    //init
    int tmp_tail = 0;
    char * tmp = new char[len];

    //delete char
    for(int i = 0; i < len; i++)
        if(mystr[i] != ch)
            tmp[tmp_tail++] = mystr[i];

    //substitute mystr with tmp
    tmp[tmp_tail] = '\0';
    delete [] mystr;
    mystr = tmp;
    len = tmp_tail;
}

void EditString::DeleteSub(char * sub)
{
    //init
    int sub_len = strlen(sub);
    if(len < sub_len)
        return;
    int tmp_tail = 0;
    int i,j;
    char * tmp = new char[len + 1];

    //search substring
    for(i = 0; i < (len - sub_len + 1); i++)
    {
        for(j = 0; j < sub_len; j++)
            if(sub[j] != mystr[i+j])
                break;
        
        //if substring is found, skip it
        if(j >= sub_len - 1 && mystr[i+sub_len-1] == sub[sub_len-1])
        {
            i = i + sub_len - 1;
            continue;
        }

        //if not, copy mystr to tmp
        tmp[tmp_tail++] = mystr[i];
    }

    //copy the rest of mystr to tmp
    for(i = len - sub_len + 1;i<len;i++)
        tmp[tmp_tail++] = mystr[i];

    //substitute mystr with tmp
    tmp[tmp_tail] = '\0';
    delete [] mystr;
    mystr = tmp;
    len = tmp_tail;
}