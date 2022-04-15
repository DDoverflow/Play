//
// Created by 陈智彬 on 2022/4/15.
//

//5.编写动态规划法求解数塔问题程序。并调用此程序求解如下数塔。
//{{18}，{12,15}，{3,8,6}，{8,10,5,12}，{16,4,18,10,9}}

#include <iostream>
#define len 5
using namespace std;

int Data(int arr[len][len]) {
    int data[len][len] = {0}, path[len][len] = {0};
    for (int rear = 0; rear < len; rear++)
        data[len - 1][rear] = arr[len - 1][rear];
    for (int front = len - 2; front >= 0; front--) {
        for (int k = 0; k <= front; k++) {
            if (data[front + 1][k] > arr[front + 1][k + 1]) {
                data[front][k] = arr[front][k] + data[front + 1][k];
                path[front][k] = k;
            }
            else {
                data[front][k] = arr[front][k] + data[front + 1][k + 1];
                path[front][k] = k + 1;
            }
        }
    }
    cout << arr[0][0];
    int l = path[0][0];
    for (int i = 1; i < len; i++) {
        cout << "->" << arr[i][l];
        l = path[i][l];
    }
    return data[0][0];
}

int main() {
    int arr[len][len] = {{18},{12,15},{3,8,6},{8,10,5,12},{16,4,18,10,9}};
    Data(arr);
    return 0;
}