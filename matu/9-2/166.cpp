#include "Vehicle.h"
#include <iostream>

using namespace std;


class Car : public Vehicle
{
    public:
        Car()
        {
            cout<<"Car constructor..."<<endl;
        }

        ~Car()
        {
            cout<<"Car destructor..."<<endl;
        }

        void display() const
        {
            cout << "This is a car!" << endl;
        }
};

class Truck : public Vehicle
{
    public:
        Truck()
        {
            cout<<"Truck constructor..."<<endl;
        }

        ~Truck()
        {
            cout<<"Truck destructor..."<<endl;
        }

        void display() const
        {
            cout << "This is a truck!" << endl;
        }
};

class Boat : public Vehicle
{
    public:
        Boat()
        {
            cout<<"Boat constructor..."<<endl;
        }

        ~Boat()
        {
            cout<<"Boat destructor..."<<endl;
        }

        void display() const
        {
            cout<<"This is a boat!" << endl;
        }
};

Vehicle * Vehicle::createCar(){return new Car();}
Vehicle * Vehicle::createTruck(){return new Truck();}
Vehicle * Vehicle::createBoat(){return new Boat();}
