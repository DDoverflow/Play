#include <iostream>
using namespace std;

class  Complex {        // 建立一个 Complex 类
public:
    double a, b;
    Complex() {}
    Complex(int a, int b): a(a), b(b) {}
    Complex &operator+(Complex &matter);    // 处理复数和复数相加的重载
    Complex &operator+(int);                // 处理复数和整数相加的重载
    Complex &operator+(double);             // 处理复数和浮点数相加的重载
};

Complex & Complex::operator+(Complex &matter) {
    Complex *middle = new Complex;
    middle->a = this->a + matter.a;
    middle->b = this->b + matter.b;
    return *middle;
}

Complex & Complex::operator+(int matter) {
    Complex *middle = new Complex;
    middle->a = this->a + matter;
    middle->b = this->b;
    return *middle;
}

Complex & Complex::operator+(double matter) {
    double front, rear;
    Complex *middle = new Complex;
    front = this->a + matter;
    rear = this->b;
    middle->a = front;
    middle->b = rear;
    return *middle;
}

ostream &operator<<(ostream &output, Complex &matter) {     // 重载 << 运算符，直接输出对象
    output << matter.a <<  " + " << matter.b << "i";
}

int main() {
    Complex matter1(10, 2), matter2(2, 5);
    cout << matter1 + matter2 << endl;
    cout << matter2 + 3 << endl;
    cout << matter2 + 3.5 << endl;
    return 0;
}