#include <iostream>
#include <cmath>
using namespace std;
class Point {
public:
    Point(int first, int second) {x = first, y = second;}
    double x, y;
    double Destination(int front, int rear) {
        int sum_x = pow(this->x - front, 2);
        int sum_y = pow(this->y - rear, 2);
        return sqrt(sum_x + sum_y);
    }
};

class Matrix: public Point {
public:
    Matrix(int first, int second, int third, int fourth): Point(first, second), length(third), width(fourth) {}
    double length, width;
    double Calculate_S() {return this->length * this->width;}
    double Calculate_C() {return (this->length + this->width) * 2;}
};

class cuboid: public Matrix {
public:
    cuboid(int first, int second, int third, int fourth, int fifth): Matrix(first, second, third, fourth), height(fifth) {}
    double height;
    double Superficial_area() {
        int first = 2 * (this->height * this->width);
        int second = 2 * (this->height * this->length);
        int third = 2 * (this->length * this->width);
        return first + second + third;
    }
    double Bulk() {return this->height * this->width * this->length;}
};

void test() {
    cuboid matter(0,0,1,2,3), content(3,4,3,2,5);
    cout << "su_area: " << matter.Superficial_area() << endl;
    cout << "Bulk: " << matter.Bulk() << endl;

    cout << "S: " << matter.Calculate_S() << endl;
    cout << "C: " << matter.Calculate_C() << endl;
    cout << "destination: " << matter.Destination(content.x, content.y) << endl;
}

int main() {
    test();
    return 0;
}