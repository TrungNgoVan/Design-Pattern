#include <iostream>

using namespace std;

class Box
{
private:
    double _length;
    double _breadth;
    double _height;

public:
    // Constructor and destructor
    
    // Setter & Getter
    void setLength(double value)
    {
        _length = value;
    }

    double getLength()
    {
        return _length;
    }

    void setBreadth(double value)
    {
        _breadth = value;
    }

    double getBreadth()
    {
        return _breadth;
    }

    void setHeight(double value)
    {
        _height = value;
    }

    double getHeight()
    {
        return _height;
    }
    // Method

    double getVolume()
    {
        return _length * _breadth * _height;
    }

    Box operator+(const Box &b)
    {
        Box newBox; // create a new Box
        newBox._length = this->_length + b._length;
        newBox._breadth = this->_breadth + b._breadth;
        newBox._height = this->_height + b._height;
        return newBox; // return object newBox
    }
};

int main()
{
    
    return 0;
}
