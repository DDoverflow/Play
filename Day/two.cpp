//
// Created by 陈智彬 on 2022/3/23.
//

#include <iostream>
using namespace std;

class  Store {
public:
    Store(int code, int count, float price): code(code), current_number(count), price(price) {};
    void total();
    void display(Store *ans, int length);
private:
    int code, current_number;
    static float discount, sum;
    float average, price;
};

float Store::discount = 0.98;
float Store::sum = 0;

void Store::total() {
    if (current_number > 10) {
        sum += (current_number * price * discount);
        average = price * discount;
    }
    else {
        sum += (current_number * price);
        average = price;
    }
}

void Store::display(Store *ans, int length) {
    cout << "all sum: " << sum << endl;
    for (int i = 0; i < length; i++)
        cout << "average price: " << ans[i].average << endl;
}

int main() {
    Store people[3] = {
            Store(101, 5, 23.5),
            Store(102, 12, 24.56),
            Store(103, 100, 21.5)
    };
    for (int k = 0; k < 3; k++) people[k].total();
    people[0].display(people, 3);
    return 0;
}