#include <iostream>
using namespace std;

// 第五题

class A {
public:
    void F1() {cout << "use F1" << endl;}
    int i;
protected:
    void F2() {cout << "use F2" << endl;}
    int j;
private:
    int k;
};

class B: public A {
public:
    void F3();
protected:
    int m;
private:
    int n;
};

void B::F3() {
    this->i = 10; this->j = 20; this->k = 30;
}

class C: public B {
public:
    void F4();
private:
    int p;
};

void C::F4() {
    this->F1();
    this->F2();
    this->F3();
}

int main() {
    A a1;
    B b1;
    C c1;

    // 1.main 是否能用 b1.i，b1.j 和 b1.k 引用派生类 B 对象 b1 中的基类 A 的成员？
    b1.i;        // 可以调用 b1.i
    b1.j;       // 无法调用 b1.j，因为 j 是 A 的保护属性的成员
    b1.k;       // 无法调用 b1.k，因为 k 是 A 的私有属性的成员

    // 2.派生类 B 中的成员函数能否调用基类 A 中的成员函数 F1，F2
    b1.F1();    // 可以调用 F1，因为 F1 是 A 中公共属性的成员
    b1.F2();     // 无法调用 F2，因为 F2 是 A 中保护属性的成员

    // 3.派生类 B 中的成员能否引用基类 A 中的数据成员 i, j, k
    // 由 24 - 26 行可知，可以引用 i 和 j，但无法引用 k

    // 4.能否在 main 函数中用 c1 去访问 A，B，C 的成员？
    c1.i;       // 可以调用 c1.i
    c1.j;       // 无法调用 c1.j，因为 j 是 A 的保护属性的成员
    c1.k;       // 无法调用 c1.k，因为 k 是 A 的私有属性的成员
    c1.m;       // 无法调用 c1.m，因为 m 是 B 的保护属性
    c1.p;       // 无法调用 c1.p，因为 p 是私有属性

    // 5.能否在 main 中使用 c1 调用所有的方法？
    c1.F1();    // 可以调用 F1
    c1.F2();    // 无法调用 F2
    c1.F3();    // 可以调用 F3
    c1.F4();    // 可以调用 F4

    // 6.C 的成员函数是否可以调用基类 A 中的成员函数和 B 中的成员函数？
    // 由 35 - 39 行可知，是可以调用的
}
