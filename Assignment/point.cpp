//
// Created by 陈智彬 on 2022/5/18.
//

#include <iostream>
using namespace std;
#include "point.h"

Point::Point(float x, float y) {this->x = x; this->y = y;}

void Point::SetPoint(float matter1, float matter2) {this->x = matter1;  this->y = matter2;}

ostream &operator<<(ostream &out, const Point &matter) {
    out << "[" << matter.x << ", " << matter.y << "]" << endl;
    return out;
}

int main() {
    Point matter(3.5, 6.4);
    cout << "x = " << matter.GetX() << ", " << "y = " << matter.GetY() << endl;
    matter.SetPoint(8.5, 6.8);
    cout << "matter(new): " << matter << endl;
}