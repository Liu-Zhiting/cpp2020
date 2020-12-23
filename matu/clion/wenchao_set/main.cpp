#include<iostream>
#include"CSet.h"
using namespace std;
bool Inside(int val, int n, int* p)
{
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		if (val == p[i])
			return true;
	}
	return false;
}
bool Set::operator <=(const Set& s)const
{
	int i = 0;
	int count = 0;
	bool t;
	for (i = 1; i <= n; i++)
	{
		t = Inside(this->pS[i], s.n, s.pS);
		if (t == true)
			count++;
	}
	if (count == n)
		return true;
	else return false;
}
bool Set::operator==(const Set& s)const
{
	if (s.n != n) { return false; }
	else
	{
		int i = 0;
		int count = 0;
		bool t;
		for (i = 1; i <= n; i++)
		{
			t = Inside(this->pS[i], s.n, s.pS);
			if (t == true)
				count++;
		}
		if (count == n )
			return true;
		else
			return false;
	}
}
//需要加const
Set& Set::operator +=(int e)
{
	bool t;
	int i;
	int * now = NULL;

	t = Inside(e, n, pS);
	if (t == true)
		return *this;
	else
	{
		n += 1;
		int* p;
		p = new int[n + 1];
		for (i = 1; i < n ; i++)
		{
			p[i] = pS[i];
		}
		p[n] = e;
		now = pS;
		pS = p;

		if(now!=NULL)
			delete[] now;

		return *this;
	}
}
//需要加const
Set& Set::operator -=(int e)
{
	bool t;
	int i=0,j=1;
	int* now;
	t = Inside(e, n, pS);
	if (t == false)
		return *this;
	else
	{
		n -= 1;
		int* p;
		p = new int[n + 1];
		for (i = 1; i <= n+1; i++)
		{
			if (pS[i] != e)
			{
				p[j] = pS[i];
				j += 1;
			}
		}
		now = pS;
		pS = p;
		//if(now!=NULL)
	//		delete []now;
		return *this;
	}
}
Set Set::operator|(const Set& s)const
{
	int i = 1;
	
	Set temp;
	//Set temp(*this);
	//*this += pS[i];

	for (i = 1; i <= n; i++)
	{
		temp += pS[i];
	}
	for (i = 1; i <= s.n; i++)
	{
		temp += s.pS[i];
	}
	return temp;
}
Set Set::operator&(const Set& s)const
{
	int i = 1;
	bool t1;
	Set *tempSet = new Set;

	for (i = 1; i <= n; i++)
	{
		cout << pS[i] << endl;
		t1 = Inside(pS[i], s.n, s.pS);
		if (t1 == true) {
			(*tempSet) += pS[i];
		}
			//temp += pS[i];
	}

	//cout<<"size:" << temp.size() << endl;
	
	return *tempSet;
}
Set Set::operator-(const Set& s)const
{
	int i = 1;
	Set temp;
	for (i = 1; i <= n; i++)
	{
		temp += pS[i];
	}
	for (i = 1; i <= s.n; i++)
	{
		temp -= s.pS[i];
	}
	return temp;
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

	t=s1&s2;
	s1.ShowElement();
	s2.ShowElement();
	t.ShowElement();
	t = s1 - s2;
	t.ShowElement();
	
	cout << "test in main\n";
	t = s1 | s2;
	t.ShowElement();
	return 0;
}