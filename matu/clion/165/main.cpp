#include <iostream>
#include <cstdlib>
using namespace std;

class Set{
private:
    int n;
    int * pS; //集合元素
public:
    Set()
    {
        n = 0;
        pS =NULL;
    }

    Set(Set &s){
        n = s.n;
        if (n !=0)
        {
            pS= new int[n+1];
            for (int i =1;i<=n;i++) //集合的下标从1开始，集合中不能有重复元素
                pS[i] = s.pS[i];
        }
    }

    ~Set(){
        if (pS)
        {
            delete []pS;
            pS = NULL;
            n =0;
        }
    }

    void ShowElement()const
    { //输出集合的元素
        int temp = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(pS[i] > pS[j])
                {
                    temp = pS[i];
                    pS[i] = pS[j];
                    pS[j] = temp;
                }
            }
        }
        cout<<"{";
        for(int i =1;i<n;i++)
            cout <<pS[i]<<",";
        if (IsEmpty())
            cout<<"}"<<endl;
        else cout<<pS[n]<<"}"<<endl;
    }

    bool IsEmpty() const  //判断集合是否为空
    {
        return (0 == n);
    }

    int size()
    {
        return n;
    }

    bool IsElement(int e)const
    {
        for (int i =1;i<=n;i++)
            if (pS[i] ==e)
                return true;
        return false;
    }

    Set & operator = (const Set &s);

    bool operator <=(const Set &s)const;

    bool operator ==(const Set &s)const;

    Set & operator +=(int e);

    Set & operator -=(int e);

    Set operator |(const Set &s)const;

    Set operator &(const Set &s)const;

    Set operator -(const Set &s)const;
};

Set &Set::operator=(const Set &s) {
    if(this == &s) return *this;

    n = s.n;
    if (n !=0)
    {
        pS= new int[n+1];
        for (int i =1;i<=n;i++) //集合的下标从1开始，集合中不能有重复元素
            pS[i] = s.pS[i];
    }
    return * this;
}

int cmpfunc(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

bool Set::operator <=(const Set &s)const
{
    if(this->n > s.n) return false;

    for(int i =1;i<=n;i++)
    {
        if(!s.IsElement(pS[i]))
            return false;
    }
    return true;

}//this <= s判断当前集合是否包于集合s

bool Set::operator ==(const Set &s)const
{
    if(this->n != s.n)
        return false;

    for(int i =1;i<=n;i++)
        if(!s.IsElement(pS[i]))
            return false;

    return true;
} //判断集合是否相等

Set & Set::operator +=(int e) // 向集合中增减元素e
{
    if(this->IsElement(e))
        return *this;

    int * tmp = new int[n+2];
    for(int i = 1; i <= n;i++)
        tmp[i] = pS[i];
    tmp[n+1] = e;
    delete [] pS;
    pS = tmp;
    n++;

    qsort(pS + 1,n,sizeof(int),cmpfunc);
    return *this;
}

Set & Set::operator -=(int e)
{
    for(int i = 1; i <= n; i++)
    {
        if(e == pS[i])
        {
            pS[i] = pS[n];
            n--;
            break;
        }
    }

    qsort(pS + 1,n,sizeof(int),cmpfunc);
    return *this;
}    //删除集合中的元素e

Set Set::operator |(const Set &s)const
{
    Set result;
    result.n = this->n;
    if (result.n !=0)
    {
        result.pS= new int[n+1];
        for (int i =1;i<=result.n;i++) //集合的下标从1开始，集合中不能有重复元素
            result.pS[i] = this->pS[i];
    }

    for(int i =1;i<=s.n;i++)
        result += s.pS[i];

    qsort(result.pS + 1,result.n,sizeof(int),cmpfunc);
    return result;
}  //集合并

Set Set::operator &(const Set &s)const
{
    Set result;
    result.n = (this->n > s.n) ? this->n : s.n;
    result.pS = new int[result.n + 1];
    int tail = 1;

    for(int i = 1; i <= this->n; i++)
    {
        for(int j = 1; j <= s.n; j++)
        {
            if(this->pS[i] != s.pS[j])
                continue;
            if(!result.IsElement(s.pS[j]))
            {
                result.pS[tail] = s.pS[j];
                tail++;
            }
        }
    }
    result.n = tail-1;

    qsort(result.pS + 1,result.n,sizeof(int),cmpfunc);
    return result;
}//集合交

Set Set::operator -(const Set &s)const
{
    Set result;
    result.n = this->n;
    if (result.n !=0)
    {
        result.pS= new int[n+1];
        for (int i =1;i<=result.n;i++) //集合的下标从1开始，集合中不能有重复元素
            result.pS[i] = this->pS[i];
    }


    for(int i =1;i<=result.n;i++)
    {
        for(int j = 1;j<= s.n;j++)
        {
            if(result.pS[i] == s.pS[j])
            {
                result.pS[i] = result.pS[result.n];
                result.n--;
                i--;
                break;
            }
        }
    }

    qsort(result.pS + 1,result.n,sizeof(int),cmpfunc);
    return result;
}

int main()
{
    Set s1,s2;
    Set t;
    s1 += 1;
    s1 += 3;
    s1 += 4;
    s2 += 2;
    s2 += 1;
    cout << "s1 = ";
    s1.ShowElement();
    cout << "s2 = ";
    s2.ShowElement();

    t=s1&s2;
    cout << "s1 & s2 = ";
    t.ShowElement();

    t = s1 - s2;
    cout << "s1 - s2 = ";
    t.ShowElement();

    t = s1 | s2;
    cout << "s1 | s2 = ";
    t.ShowElement();

    s2 -= 2;
    cout << "s2 = ";
    s2.ShowElement();

    cout << "Is s2 subset of s1?\t";
    cout << ((s2<=s1)? "yes" : "no") << endl;

    s1 -= 3;
    s1 -= 4;
    cout << "Is s1 equal to s2?\t" << ((s2==s1)? "yes" : "no") << endl;

    return 0;
}