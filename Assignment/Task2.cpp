#include <iostream>
#define PI 3.14
#include <cmath>
#define len 5
using namespace std;

// 作业第五题

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

class Square: public Shape {
public:
    int data;
    Square(int data): data(data) {}
    double PrintArea() {return pow(data, 2);}
};

class Trapezoid: public Shape {
public:
    int up, down, height;
    Trapezoid(int up, int down, int height): up(up), down(down), height(height) {}
    double PrintArea() {return (up + down) * height / 2;}
};

int main() {
    Shape **matter = new Shape*[len];
    matter[0] = new Circle(2);
    matter[1] = new Rectangle(2, 3);
    matter[2] = new Triangle(3,4,5);
    matter[3] = new Square(5);
    matter[4] = new Trapezoid(2,3,4);
    cout << "Circle: " << matter[0]->PrintArea() << endl;
    cout << "Rectangle: " << matter[1]->PrintArea() << endl;
    cout << "Triangle: " << matter[2]->PrintArea() << endl;
    cout << "Square: " << matter[3]->PrintArea() << endl;
    cout << "Trapezoid: " << matter[4]->PrintArea() << endl;
    double sum = 0;
    for (int num = 0; num < len; num++) sum += matter[num]->PrintArea();
    cout << "Sum: " << sum << endl;
}