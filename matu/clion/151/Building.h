#include <iostream>
#include <cstring>
using namespace std;
class Building{
public:
    Building(char *name,int floor,int room,int area){
        strcpy(this->name,name);
        this->floor = floor;
        this->room = room;
        this->area = area;
    }
    virtual void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
    }
    Building * createTeachBuilding(char *name,int floor,int room,int area,char *function);
    Building * creatDormBuilding(char *name,int floor,int room,int area,int peoples);
protected:
    char name[20];
    int floor;
    int room;
    float area;

};