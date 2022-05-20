//
// Created by 陈智彬 on 2022/5/18.
//

#include <iostream>
using namespace std;
#include "circle.h"

void Circle::SetRadius(float matter) {radius = matter;}

Circle::Circle(float x, float y, float r): Point(x, y), radius(r) {}

float Circle::GetRadius() const {return radius;}

float Circle::area() const {return 3.14159 * radius * radius;}

ostream &operator<<(ostream &output, const Circle &matter) {
    output << "Center = [" << matter.x << ", " << matter.y << "], r = " << matter.radius;
    output << ", area = " << matter.area() << endl;
    return output;
}

int main() {
    Circle matter(3.5, 6.4, 5.2);
    cout << "original circle: \nx = " << matter.GetX() << ", y = " << matter.GetY();
    cout << ", r = " << matter.GetRadius() << ", area = " << matter.area() << endl;
    matter.SetRadius(7.5);
    matter.SetPoint(5, 5);
    cout << "New circle: \n" << matter;
    Point &content = matter;
    cout << "content: " << content;
}