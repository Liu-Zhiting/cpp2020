#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    private:
        double x,y;

    public:
        Point(double x, double y)
        {
            this->x = x; this->y = y;
        }

        double Distance(const Point & p)
        {
            return sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y)*(this->y - p.y));
        }
};

int main(){
    double a,b,c,d;
	cin>>a>>b>>c>>d;
	Point A(a,b),B(c,d);
	cout<<A.Distance(B)<<endl;
	return 0;
}