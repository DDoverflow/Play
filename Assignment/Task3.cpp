#include <iostream>
using namespace std;

class Person {
public:
    virtual void Input(string, string, int, int) = 0;
    virtual void Input(string, string, string, string) = 0;
    virtual void Exhibition() = 0;
protected:
    string code;
    string name;
};


class Student: public Person {
public:
    void Input(string, string, int, int);
    void Input(string, string, string, string) {}
    void Exhibition();
private:
    int s_class;
    int age;
};

void Student::Input(string code, string name, int sc, int sa) {
    this->code = code;
    this->name = name;
    this->s_class = sc;
    this->age = sa;
}

void Student::Exhibition() {
    cout << "code: " << this->code << endl;
    cout << "name: " << this->name << endl;
    cout << "s_class: " << this->s_class << endl;
    cout << "age: " << this->age << endl;
}


class  Teacher: public Person {
public:
    void Input(string, string, string, string);
    void Input(string, string, int, int) {}
    void Exhibition();
private:
    string career;
    string department;
};

void Teacher::Input(string code, string name, string car, string dep) {
    this->code = code;
    this->name = name;
    this->career = car;
    this->department = dep;
}

void Teacher::Exhibition() {
    cout << "code: " << this->code << endl;
    cout << "name: " << this->name << endl;
    cout << "career: " << this->career << endl;
    cout << "department: " << this->department << endl;
}

int main() {
    Teacher matter;
    matter.Input("101", "Jack", "Professor", "Computer");
    matter.Exhibition();

    Student substance;
    substance.Input("2001", "Tom", 3, 12);
    substance.Exhibition();
    return 0;
}