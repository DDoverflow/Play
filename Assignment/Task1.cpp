#include <iostream>
using namespace std;

class Point {
public:
    Point(float x = 0, float y = 0);
    void SetPoint(float matter1, float matter2);
    float GetX() const {return x;}
    float GetY() const {return y;}
    friend ostream &operator<<(ostream &out, const Point &matter);

protected:
    float x, y;
};

Point::Point(float x, float y) {this->x = x; this->y = y;}

void Point::SetPoint(float matter1, float matter2) {this->x = matter1;  this->y = matter2;}

ostream &operator<<(ostream &out, const Point &matter) {
    out << "[" << matter.x << ", " << matter.y << "]" << endl;
    return out;
}


class Circle: public Point {
public:
    Circle(float x = 0, float y = 0, float r = 0);
    void SetRadius(float matter);
    float GetRadius() const;
    float area() const;
    friend ostream &operator<<(ostream &output, const Circle &matter);

private:
    float radius;
};

void Circle::SetRadius(float matter) {radius = matter;}

Circle::Circle(float x, float y, float r): Point(x, y), radius(r) {}

float Circle::GetRadius() const {return radius;}

float Circle::area() const {return 3.14159 * radius * radius;}

ostream &operator<<(ostream &output, const Circle &matter) {
    output << "Center = [" << matter.x << ", " << matter.y << "], r = " << matter.radius;
    output << ", area = " << matter.area() << endl;
    return output;
}


class Cylinder: public Circle {
public:
    Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
    void SetHeight(float matter);
    float GetHeight() const;
    float area() const;
    float volume() const;
    friend ostream &operator<<(ostream &output, const Cylinder &matter);
protected:
    float height;
};

Cylinder::Cylinder(float x, float y, float r, float h): Circle(x, y, r), height(h) {}

void Cylinder::SetHeight(float matter) {height = matter;}

float Cylinder::GetHeight() const {return height;}

float Cylinder::area() const {return 2 * Circle::area() + 2 * 3.14159 * Circle::GetRadius() * height;}

float Cylinder::volume() const {return Circle::area() * height;}

ostream &operator<<(ostream &output, const Cylinder &matter) {
    output << "Center = [" << matter.x << ", " << matter.y << "], " << matter.GetRadius();
    output << ", h = " << matter.height << "\narea = " << matter.area() << ", volume = ";
    output << matter.volume() << endl;
    return output;
}

int main() {
    /* 调试 Point 类
    Point matter(3.5, 6.4);
    cout << "x = " << matter.GetX() << ", " << "y = " << matter.GetY() << endl;
    matter.SetPoint(8.5, 6.8);
    cout << "matter(new): " << matter << endl;
    */

    /* 调试 Circle 类
    Circle matter(3.5, 6.4, 5.2);
    cout << "original circle: \nx = " << matter.GetX() << ", y = " << matter.GetY();
    cout << ", r = " << matter.GetRadius() << ", area = " << matter.area() << endl;
    matter.SetRadius(7.5);
    matter.SetPoint(5, 5);
    cout << "New circle: \n" << matter;
    Point &content = matter;
    cout << "content: " << content;
    */

    /*  调试 Cylinder 类，这里注意，因为 Circle 类中的 radius 是私有属性，所以在 Cylinder 无法直接获取，必须使用 GetRadius 来获取
    Cylinder matter(3.5, 6.4, 5.2, 10);
    cout << "original cylinder: \nx = " << matter.GetX() << ", y = " << matter.GetY();
    cout << ", r = " << matter.GetRadius() << ", h = " << matter.GetHeight() << "\narea = ";
    cout << matter.area() << ", volume: " << matter.volume() << endl;

    matter.SetHeight(15);
    matter.SetRadius(7.5);
    matter.SetPoint(5,5);
    cout << "\nNew Cylinder: \n" << matter;
    Point &content1 = matter;
    cout << "\ncontent1 as a Point: " << content1;
    Circle &content2 = matter;
    cout << "\ncontent2 as a Circle: " << content2;
    */
    return 0;
}