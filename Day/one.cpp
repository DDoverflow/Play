//
// Created by 陈智彬 on 2022/3/23.
//

#include <iostream>
using namespace std;

class  Student {
public:
    Student(int n, int a, float s): num(n), age(a), score(s) {}
    void total();
    static float average();
private:
    int num, age;
    float score;
    static float sum;
    static int count;
};

void Student::total() {
    sum += this->score;
    count++;
}

float Student::average() {return sum / count;}
float Student::sum = 0;
int Student::count = 0;

int main() {
    Student arr[3] = {Student(1001, 18, 70), Student(1002, 19, 78), Student(1005, 20, 98)};
    int count;
    cout << "please enter count: ";     cin >> count;
    for (int k = 0; k < count; k++) arr[k].total();
    cout << "Student count: " << count << ",\t" << "average score: " << arr[0].average() << endl;
    return 0;
}