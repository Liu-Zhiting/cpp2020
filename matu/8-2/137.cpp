#include<iostream>
#include <cmath>
using namespace std;
class Ctriangle
{
    private:
        double a,b,c;
    public:
    Ctriangle(double a, double b, double c)
    {
        this->a = a; this->b = b; this->c = c;
    }

    double GetPerimeter()
    {
        return a+b+c;
    }

    double GetArea()
    {
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    void display()
    {
        cout << "Ctriangle:a=" << a <<",b="<<b <<",c=" << c << endl;
    }

};


int main(){
	double a,b,c;
	cin>>a>>b>>c;
	Ctriangle T(a,b,c);
	T.display();
	cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
	cout<<"Area:"<<T.GetArea()<<endl;
	return 0;	 
}