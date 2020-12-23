#include "ShapeFactory.h"

class Triangle : public ShapeFactory
{
private:
    float a, b, c;
public:
    Triangle(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    float Circumstance()
    {
        return this->a + this->b + this->c;
    }
};

class Rectangle : public ShapeFactory
{
private:
    float a, b, c, d;
public:
    Rectangle(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float Circumstance()
    {
        return this->a + this->b + this->c + this-> d;
    }
};

class Circle :public ShapeFactory
{
private:
    float r;

public:
    Circle(float r)
    {
        this->r = r;
    }

    float Circumstance()
    {
        return 3.14 * 2 * r;
    }
};

ShapeFactory * ShapeFactory::Create(float a,float b,float c)
{

    ShapeFactory *p=new Triangle(a,b,c);
    return p;
}

ShapeFactory * ShapeFactory::Create(float a,float b,float c, float d)
{

    ShapeFactory *p=new Rectangle(a,b,c,d);
    return p;
}

ShapeFactory * ShapeFactory::Create(float r)
{
    ShapeFactory *p=new Circle(r);
    return p;
}