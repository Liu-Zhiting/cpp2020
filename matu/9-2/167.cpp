#include <iostream>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape
{
    private:
        double length,width;

    public:
        Rectangle(double l,double w)
        {
            this->length = l;
            this->width = w;
        }

        double GetArea()
        {
            return length * width;
        }

        double GetPerimeter()
        {
            return 2*(width + length);
        }
};

class Circle : public Shape
{
    private:
        double radius;

    public:
        Circle(double r)
        {
            this->radius = r;
        }

        double GetArea()
        {
            return radius * radius * 3.14;
        }

        double GetPerimeter()
        {
            return radius * 3.14 * 2;
        }
};

Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}