#include <iostream>
#include <cstring>

using namespace std;

typedef struct UserInfo{
    char* name;
    char* password;
    struct UserInfo* next;
} UserInfo;

class User
{
    public:
    User(char * name, char* password)
    {
        userInfo = new UserInfo;
        userInfo->name = name;
        userInfo->password = password;
        userInfo->next = NULL;
    }

    void AddUser(char * name, char* password)
    {
        userInfo->next = new UserInfo;
        userInfo->next->name = name;
        userInfo->next->password = password;
        userInfo->next->next = NULL;
    }

    int login(char *name,char *pass)
    {
        UserInfo * p = this->userInfo;
        int count = 1;

        while(p != NULL)
        {
            if(0 == strcmp(p->name,name) && 0 == strcmp(p->password,pass))
                return count;

            count++;
            p = p->next;
        }
        return -1;
    }

    private:
    UserInfo* userInfo;
};

int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	return 0;
}
