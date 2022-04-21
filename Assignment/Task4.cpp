#include <iostream>
using namespace std;

class  Person {
public:
    virtual void Show() {cout << "This is Person class" << endl;}
};

class  Student: public Person {
public:
    void Show() {cout << "This is Student class" << endl;}
};

class  Teacher: public Person {
public:
    void Show() {cout << "This is Teacher class" << endl;}
};

void Exhibition(Person &matter) {
    matter.Show();
}

int main() {
    Person *current = new Student;
    current->Show();
    delete current;
    current = new Teacher;
    current->Show();
    return 0;
}