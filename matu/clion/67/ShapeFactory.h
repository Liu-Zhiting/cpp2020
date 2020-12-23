class ShapeFactory
{
public:
    ShapeFactory(){};
    virtual ~ShapeFactory(){};

    virtual float Circumstance(){return 0;};
    ShapeFactory *Create(float a,float b,float c);
    ShapeFactory *Create(float a,float b,float c,float d);
    ShapeFactory *Create(float r);
};