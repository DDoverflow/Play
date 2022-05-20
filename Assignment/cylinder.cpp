//
// Created by 陈智彬 on 2022/5/18.
//

#include <iostream>
using namespace std;
#include "cylinder.h"

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
}