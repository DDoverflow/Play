#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

// 作业第四题

class Shape {
public:
    virtual double PrintArea() = 0;
};

class Circle: public Shape {
public:
    Circle(int data): r(data) {}
    int r;
    double PrintArea() {return PI * r * r;}
};

class Rectangle: public Shape {
public:
    int x, y;
    Rectangle(int x, int y): x(x), y(y) {}
    double PrintArea() {return x * y;}
};

class Triangle: public Shape {
public:
    int a, b, c;
    Triangle(int a, int b, int c): a(a), b(b), c(c) {}
    double PrintArea() {
        double C = (a + b + c) / 2;
        return sqrt(C * (C - a) * (C - b) * (C - c));
    }
};

int main() {
    Shape *matter = new Circle(2);
    cout << "Circle: " << matter->PrintArea() << endl;
    delete matter;
    matter = new Rectangle(3, 4);
    cout << "Rectangle: " << matter->PrintArea() << endl;
    delete matter;
    matter = new Triangle(3,4,5);
    cout << "Triangle: " << matter->PrintArea() << endl;
    return 0;
}