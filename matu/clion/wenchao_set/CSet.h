#pragma once
#include <iostream>
using namespace std;
class Set {
private:
	int n;
	int* pS; //����Ԫ��
public:
	Set() { n = 0; pS = NULL; }
	Set( Set& s) {
		n = s.n;
		if (n != 0)
		{
			pS = new  int[n + 1];
			for (int i = 1; i <= n; i++) //���ϵ��±��1��ʼ�������в������ظ�Ԫ��
				pS[i] = s.pS[i];
		}
	}
	~Set() {

		if (pS)
		{
		    cout << "=========\n" <<  "      finalize function called" << endl;
			cout << "      size:" << n << endl;
			for(int i = 1; i <= n;i++)
            {
			    cout << "      elem[" << i << "] = " << pS[i] << endl;
            }
			cout << "=========\n";
			//delete []pS;
			pS = NULL;
			n = 0;

			
		}

	}
	void ShowElement()const { //������ϵ�Ԫ��
		int temp = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (pS[i] > pS[j])
				{
					temp = pS[i];
					pS[i] = pS[j];
					pS[j] = temp;
				}
			}
		}
		cout << "{";
		for (int i = 1; i < n; i++)
			cout << pS[i] << ",";
		if (IsEmpty())
			cout << "}" << endl;
		else cout << pS[n] << "}" << endl;
	}

	bool IsEmpty()const { return n ? false : true; } //�жϼ����Ƿ�Ϊ��
	int size() { return n; }
	bool IsElement(int e)const {
		for (int i = 1; i <= n; i++)
			if (pS[i] == e)
				return true;
		return  false;
	}
	bool operator <=(const Set& s)const;//this <= s�жϵ�ǰ�����Ƿ���ڼ���s
	bool operator ==(const Set& s)const; //�жϼ����Ƿ����
	Set& operator +=(int e);    // �򼯺�������Ԫ��e
	Set& operator -=(int e);    //ɾ�������е�Ԫ��e

	Set operator |(const Set& s)const;  //���ϲ�
	Set operator &(const Set& s)const;//���Ͻ�
	Set operator -(const Set& s)const; //���ϲ�
};