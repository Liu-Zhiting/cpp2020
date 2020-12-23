#include <iostream>
#include <cstring>
using namespace std;

class Table
{
    protected:
        float high;

    public:
        Table(float high)
        {
            this->high = high;
        }

        float GetHigh()
        {
            return high;
        }
};

class Circle
{
    protected:
        float radius;

    public:
        Circle(float radius)
        {
            this->radius = radius;
        }

        float GetArea()
        {
            return 3.14 * radius * radius;
        }
};

class RoundTable : public Table, public Circle
{
    protected:
        char color[20];

    public:
        RoundTable(float radius,float high,char* color): Table(high),Circle(radius)
        {
            this->high = high;
            this->radius = radius;
            strcpy(this->color,color);
        }

        char* GetColor()
        {
            return color;
        }
};

int main(){
    float radius,high;
	char color[20];
	cin>>radius>>high>>color;
	
	RoundTable RT(radius,high,color);
	cout<<"Area:"<<RT.GetArea()<<endl;
	cout<<"High:"<<RT.GetHigh()<<endl;
	cout<<"Color:"<<RT.GetColor()<<endl;
	return 0;
}