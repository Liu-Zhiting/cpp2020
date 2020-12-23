#include <iostream>
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

    Set & operator = (const Set &s)
    {
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

    bool operator <=(const Set &s)const
    {
        if(this->n > s.n) return false;

        for(int i =1;i<=n;i++)
        {
            if(!s.IsElement(pS[i]))
                return false;
        }
        return true;

    }//this <= s判断当前集合是否包于集合s

    bool operator ==(const Set &s)const
    {
        if(this->n != s.n)
            return false;

        for(int i =1;i<=n;i++)
            if(!s.IsElement(pS[i]))
                return false;

        return true;
    } //判断集合是否相等

    Set & operator +=(int e) // 向集合中增减元素e
    {
        if(this->IsElement(e))
            return *this;

        int * tmp = new int[n+2];
        for(int i = 1; i <= n;i++)
            tmp[i] = pS[i];
        tmp[n+1] = e;
        delete [] pS;
        pS = tmp;
        return *this;
    }

    Set & operator -=(int e)
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

        return *this;
    }    //删除集合中的元素e

    Set operator |(const Set &s)const
    {
        Set result;
        result = (*this);

        for(int i =1;i<=s.n;i++)
            result += s.pS[i];

        return result;
    }  //集合并

    Set operator &(const Set &s)const
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

        return result;
    }//集合交

    Set operator -(const Set &s)const
    {
        Set result;
        result = *this;

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

        return result;
    } //集合差
};