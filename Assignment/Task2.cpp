#include <iostream>
using namespace std;

class Point {
public:
    Point(float x = 0, float y = 0);
    void SetPoint(float matter1, float matter2);
    float GetX() const {return x;}
    float GetY() const {return y;}
    virtual float area() const = 0;
protected:
    float x, y;
};

Point::Point(float x, float y) {this->x = x; this->y = y;}

void Point::SetPoint(float matter1, float matter2) {this->x = matter1;  this->y = matter2;}


class Circle: public Point {
public:
    Circle(float x = 0, float y = 0, float r = 0);
    void SetRadius(float matter);
    float GetRadius() const;
    virtual float area() const;
private:
    float radius;
};

Circle::Circle(float x, float y, float r): Point(x, y), radius(r) {}

void Circle::SetRadius(float matter) {radius = matter;}

float Circle::GetRadius() const {return radius;}

float Circle::area() const {return 3.14159 * radius * radius;}


class Cylinder: public Circle {
public:
    Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
    void SetHeight(float matter);
    float GetHeight() const;
    virtual float area() const;
protected:
    float height;
};

Cylinder::Cylinder(float x, float y, float r, float h): Circle(x, y, r), height(h) {}

void Cylinder::SetHeight(float matter) {height = matter;}

float Cylinder::GetHeight() const {return height;}

float Cylinder::area() const {return 2 * Circle::area() + 2 * 3.14159 * Circle::GetRadius() * height;}


int main() {
    Point *matter = new Circle(3.5, 6.4, 5.2);
    cout << "Circle area: " << matter->area() << endl;
    matter = new Cylinder(3.5, 6.4, 5.2, 10);
    cout << "Cylinder area: " << matter->area() << endl;
    return 0;
}