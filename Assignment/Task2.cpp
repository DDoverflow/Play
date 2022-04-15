//
// Created by 陈智彬 on 2022/4/15.
//

#include <iostream>
using namespace std;

int coin[] = {8,8,8,8,8,8,8,5,8,8,8,8,8}, length = sizeof(coin) / sizeof(coin[0]);

int Find(int low, int high, int count) {
    int num1, num2, num3, add1 = 0, add2 = 0;
    if (count == 1) return low + 1;
    else if (count % 3 == 0) num1 = num2 = (count / 3);
    else num1 = num2 = (count / 3) + 1;
    num3 = count - num1 - num2;
    for (int k = 0; k < num1; k++)
        add1 += coin[low + k];
    for (int k = num1; k < num1 + num2; k++)
        add2 += coin[low + k];
    if (add1 < add2) return Find(low, low + num1 - 1, num1);
    else if (add1 > add2) return Find(low + num1, low + num1 + num2 - 1, num2);
    else return Find(low + num1 + num2, high, num3);
}

int main() {
    cout << "locate: " << Find(0, length - 1, length) << endl;
    return 0;
}