#include <iostream>
#include <cstring>
using namespace std;
class String{
protected:
	char *mystr;
	int len;
public:
	String(const char *p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	~String(){
		if (mystr !=NULL)
		{
			delete []mystr;
			mystr = NULL;
			len = 0;
		}
	}
	void showStr(){cout <<mystr;}
	char * GetStr(){return mystr;}
	virtual bool IsSubString(const char *str){
		int i,j;
		for (i =0;i<len;i++)
		{
			int k = i;
			for (j =0;str[j] !='\0';j++,k++)
			{
				if (str[j]!= mystr[k]) break;
			}
			if(str[j] =='\0') return true;
		}
		return false;
	}
};

class EditString:public String{
public:
	EditString(const char *p):String(p){}
	int IsSubString(int start, const char *str);
	void EditChar(char s, char d);
	void EditSub(char * subs,char *subd);

	void DeleteChar(char ch);
	void DeleteSub(char * sub);

};