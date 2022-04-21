#include <iostream>
using namespace std;

// 第六题

class A {
public:
    void F1();
protected:
    void F2();
private:
    int i;
};

void A::F1() {
    this->F2();
    this->i;
}

void A::F2() {
    this->F1();
    this->i;
}

class B: public A {
public:
    void F3();
    int k;
private:
    int m;
};

void B::F3() {
    this->F1();
    this->F2();
    this->k;
    this->m;
}

class C: protected B {
public:
    void F4();
protected:
    int m;
private:
    int n;
};

void C::F4() {
    this->
}

class D: private C {
public:
    void F5();
protected:
    int p;
private:
    int q;
};

void D::F5() {
    this->q;
    this->p;
    this->F2();
    this->F1();
    this->F4();
    this->F3();
    this->k;
    this->m;
}

int main() {
    A a1;
    B b1;
    C c1;
    D d1;

    // 1.类 A 的成员和对象
    // a1 只能访问 F1 函数
    // F1 和 F2 可以调用 A 中所有的成员

    // 2.类 B 的成员和对象
    // b1 能调用 A 的公共属性的成员，也就是 F1，还有自己的公共属性的成员 F3、k
    // F3 可以访问 A 的公共属性和保护属性的成员，也就是 F1, F2，还有自己的所有成员 F3, k, m

    // 3.类 C 的成员和对象
    // c1 只能调用自己的公共属性的成员 F4，其余全为保护属性，无法在类外访问
    // F4 可以访问 A、B 中所有公共属性和保护属性的成员，F1、F2、F3、F4、k、C 中的 m、n

    // 4.类 D 的成员和对象
    // d1 只能调用自己的公共属性成员 F5，其余全为私有属性，无法再类外访问
    // F5 可以访问 A、B、C 中所有公共属性和保护属性的成员，F1、F2、F3、F4、F5、p、q、C 的 m、k
}