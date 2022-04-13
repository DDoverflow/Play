//
// Created by 陈智彬 on 2022/3/30.
//

#include <iostream>
using namespace std;

class  Student {
    friend string Grade(Student &);
    friend int main();
public:
    Student(string name, double score);
private:
    string name;
    double score;
};

string Grade(Student &matter) {
    switch (int(matter.score) / 10) {
        case 10:;
        case 9: return "优";
        case 8: return "良";
        case 7: return "中";
        case 6: return "及格";
        default: return "不及格";
    }
}

Student::Student(string name, double score) {
    this->name = name;
    this->score = score;
}

int main() {
    Student first("Jack", 90), second("Tom", 83);
    Student third("Lisa", 72), fourth("Ben", 69);
    Student fifth("Quern", 49);
    cout << first.name << ": " << Grade(first) << endl;
    cout << second.name << ": " << Grade(second) << endl;
    cout << third.name << ": " << Grade(third) << endl;
    cout << fourth.name << ": " << Grade(fourth) << endl;
    cout << fifth.name << ": " << Grade(fifth) << endl;
    return 0;
}