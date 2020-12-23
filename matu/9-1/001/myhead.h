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