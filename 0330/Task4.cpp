//
// Created by 陈智彬 on 2022/3/30.
//

#include <iostream>
#include <cmath>
using namespace std;

class  Line;
class  Point {
public:
    friend double Calculate(Point &matter1, Line &matter2);
    Point(double x, double y);
private:
    double x, y;
};

class  Line {
public:
    friend double Calculate(Point &matter1, Line &matter2);
    Line(double a, double b, double c);
private:
    double a, b, c;
};

double Calculate(Point &matter1, Line &matter2) {
    double up = matter2.a * matter1.x + matter2.b * matter1.y + matter2.c;
    double down = sqrt(pow(matter2.a, 2) + pow(matter2.b, 2));
    return up / down;
}

Point::Point(double x, double y): x(x), y(y) {}
Line::Line(double a, double b, double c): a(a), b(b), c(c) {}

int main() {
    Point matter1(2, 3);
    Line matter2(3, 4,2);
    cout << "res: " << Calculate(matter1, matter2) << endl;
}