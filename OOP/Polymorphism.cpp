#include <iostream>

using namespace std;

class Shape
{
protected:
    // Attribute
    int _height, _width;

public:
    Shape(int height, int width)
    {
        _height = height;
        _width = width;
    }

    virtual double area() = 0;
};

class Rectangle : public Shape
{
public:
    // Constructor
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}

    double area()
    {
        return (_height * _width * 1.0);
    }
};

class Triangle : public Shape
{
public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}

    double area()
    {
        return (_width * _height / (2 * 1.0));
    }
};



int main()
{
    Triangle a(1,5);
    cout << a.area();
    return 0;
}
