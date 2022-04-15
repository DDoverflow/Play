//
// Created by 陈智彬 on 2022/4/15.
//

#include <iostream>

using namespace std;

//4.编程：对于序列A={5, 4, 8, 6, 3, 6, 9, 7}，
//用动态规划法求解最长递增子序列。


int Find_Max(int arr[], int length) {
    if (length == 1) return arr[length - 1];
    int current[length], ans = 0;
    for (int k = 0; k < length; k++) current[k] = 1;
    for (int k = 1; k < length; k++) {
        for (int i = 0; i < k; i++) {
            if (arr[i] < arr[k]) {
                current[k] = max(current[k], current[i] + 1);
                ans = max(ans, current[k]);
            }
        }
    }
    return ans;
}

int main() {
    int arr[] = {5, 4, 8, 6, 3, 6, 9, 7}, length = sizeof(arr) / sizeof(arr[0]);
    cout << "Max: " << Find_Max(arr, length) << endl;
    return 0;
}