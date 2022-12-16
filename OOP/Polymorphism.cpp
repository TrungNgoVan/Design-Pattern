#include <iostream>

using namespace std;

class Shape
{
private:
    // Attribute
    int _height, _width;

public:
    Shape(int height, int width)
    {
        _height = height;
        _width = width;
    }

    virtual int area() = 0;
};

class Rectangle : public Shape
{
public:
    // Constructor
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area()
    {
        return (_height * _width);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    int area()
    {
        return (width * height / 2);
    }
};



int main()
{

    return 0;
}
