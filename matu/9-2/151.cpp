#include "Building.h"
#include <iostream>
using namespace std;

class TeachBuilding : public Building
{
protected:
    char function[20];
public:

    TeachBuilding(char *name,int floor,int room,int area,char *function) : Building(name,floor,room,area)
    {
        strcpy(this->name,name);
        this->floor = floor;
        this->room = room;
        this->area = area;
        strcpy(this->function,function);
    }

    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout << "Function:" << function<<endl;
    }

};

class DormBuilding : public Building
{
protected:
    int peoples;
public:

    DormBuilding(char *name,int floor,int room,int area,int peoples) : Building(name,floor,room,area)
    {
        strcpy(this->name,name);
        this->floor = floor;
        this->room = room;
        this->area = area;
        this->peoples = peoples;
    }
    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout << "Peoples:" << peoples<<endl;
    }
};

Building* Building::createTeachBuilding(char *name,int floor,int room,int area,char *function){
    return  new TeachBuilding(name,floor,room,area,function);
}

Building * Building::creatDormBuilding(char *name,int floor,int room,int area,int peoples){
    return new DormBuilding(name,floor,room,area,peoples);
}