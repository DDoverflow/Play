#include <iostream>
using namespace std;

class Teacher {
public:
    Teacher(string name, string sex, string address, string tel_phone, int age);
    string name, sex, address, tel_phone;
    int age;
    void Display();
};

Teacher::Teacher(string name, string sex, string address, string tel_phone, int age) {
    this->name = name;
    this->sex = sex;
    this->address = address;
    this->tel_phone = tel_phone;
    this->age = age;
}

void Teacher::Display() {
    cout << "name: " << this->name << endl;
    cout << "sex: " << this->sex << endl;
    cout << "address: " << this->address << endl;
    cout << "tel_phone: " << this->tel_phone << endl;
    cout << "age: " << this->age << endl;
}

class Cadre {
public:
    Cadre(string name, string sex, string address, string tel_phone, int age);
    string name, sex, address, tel_phone, post;
    int age;
    void Display();
};

void Cadre::Display() {
    cout << "name: " << this->name << endl;
    cout << "sex: " << this->sex << endl;
    cout << "address: " << this->address << endl;
    cout << "tel_phone: " << this->tel_phone << endl;
    cout << "age: " << this->age << endl;
}

Cadre::Cadre(string name, string sex, string address, string tel_phone, int age) {
    this->name = name;
    this->sex = sex;
    this->address = address;
    this->tel_phone = tel_phone;
    this->age = age;
}

class Teacher_Cadre: public Teacher, public Cadre {
public:
    Teacher_Cadre(string name, string sex1, string sex2, string address1, string address2, string phone1, string phone2, int age1, int age2):
            Teacher(name, sex1, address1, phone1, age1), Cadre(name, sex2, address2, phone2, age2) {}
    string title;
    int wages;
    void Show() {this->Teacher::Display();}
};

int main() {
    Teacher_Cadre matter("Jack", "male", "female", "北京", "上海", "121", "130", 19, 20);
    matter.Teacher::Display();
    matter.Cadre::Display();
    matter.Show();
}