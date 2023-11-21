#include<iostream>
#include<string.h>
using namespace std;

class Shape
{
public:
    char name[50];
    int angles;

    void getName(char *nam)
    {
        strcpy(name, nam);
    }

    void getAngles(int ang)
    {
        angles = ang;
    }

    void getArea()
    {
        cout << "\nCalculating the area" << endl;
    }
};

class Triangle : public Shape
{
    float base;
    float height;

public:
    float Area;

    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    void getArea()
    {
        Area = 0.5 * base * height;
    }

    void show()
    {
        cout << "name: " << name << endl;
        cout << "Angles: " << angles << endl;
        cout << "base: " << base << " " << "height: " << height << endl;
        cout << "Area: " << Area << endl;
    }
};

class Rectangle : public Shape
{
    float length;
    float width;

public:
    float Area;

    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void getArea()
    {
        Area = length * width;
    }

    void show()
    {
        cout << "name: " << name << endl;
        cout << "Angles: " << angles << endl;
        cout << "length: " << length << " " << "width: " << width << endl;
        cout << "Area: " << Area << endl;
    }
};

int main()
{
    Shape ob;
    Triangle T(10, 20);
    T.getName("Triangle");
    T.getAngles(3);
    T.getArea();
    T.show();
    cout << endl;

    Rectangle R(10, 20);
    R.getName("Rectangle");
    R.getAngles(4);
    R.getArea();
    R.show();

    return 0;
}
