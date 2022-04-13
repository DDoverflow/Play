//
// Created by 陈智彬 on 2022/3/23.
//

#include <iostream>
#define len 3
using namespace std;

class  Student {
private:
    string name;
    float score;
    static float min_score, max_score;
public:
    void compare(Student *contents, int length);
    double divise();
    Student(string name, float score): name(name), score(score) {}
};

float Student::min_score = 65535;
float Student::max_score = 0;

void Student::compare(Student *contents, int length) {
    for (int k = 0; k < length; k++) {
        if (contents[k].score > max_score) max_score = contents[k].score;
        else if (contents[k].score < min_score) min_score = contents[k].score;
    }
}

double Student::divise() {return max_score - min_score;}

int main() {
    Student arr[len] = {
            Student("Jack", 98),
            Student("Tom", 94),
            Student("Lisa", 92)
    };
    arr[0].compare(arr, len);
    cout << "gap: " << arr[0].divise() << endl;
    cout << "length: " << sizeof(arr) / sizeof(arr[0]) << endl;
    return 0;
}