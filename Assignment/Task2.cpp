#include <iostream>
using namespace std;
#include <cmath>

class Point {
public:
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    Point(Point &matter) {this->x = matter.x;  this->y = matter.y;}
    double x, y;
};

class Line {
public:
    Line() {}
    Line(double x1, double y1, double x2, double y2): po1(x1, y1), po2(x2, y2) {}
    Line(Line &matter) {this->po1 = matter.po1;  this->po2 = matter.po2;}
    Point po1;
    Point po2;
    double Length() {return sqrt(pow(po1.x - po2.x, 2) + pow(po1.y - po2.y, 2));}
};

class Triangle {
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double x5, double y5,
        double x6, double y6): line1(x1, y1, x2, y2), line2(x3, y3, x4, y4), line3(x5, y5, x6, y6) {}
    Line line1;
    Line line2;
    Line line3;
    bool Structure_triangle();
    double Proportion();
};

bool Triangle::Structure_triangle() {
    double len1 = line1.Length(), len2 = line2.Length(), len3 = line3.Length();
    if (len1 + len2 < len3 || len1 + len3 < len2 || len2 + len3 < len1) return false;
    return true;
}

double Triangle::Proportion() {
    if (Structure_triangle()) {
        double Perimeter = (line1.Length() + line2.Length() + line3.Length()) / 2;
        double first = Perimeter - line1.Length(), second = Perimeter - line2.Length(), third =
                Perimeter - line3.Length();
        return sqrt(Perimeter * first * second * third);
    }
    return -1;
}

int main() {
    Triangle matter(1,3,4,7,4,6,8,4,2,1,3,2);
    cout << "Str_triangle: " << matter.Structure_triangle() << endl;
    cout << "proportion: " << matter.Proportion() << endl;
    return 0;
}
