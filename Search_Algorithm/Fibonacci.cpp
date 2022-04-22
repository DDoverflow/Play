#include <iostream>
using namespace std;

void Fibonacci(int arr[], int length) {
    arr[0] = 0, arr[1] = 1;
    for (int num = 2; num < length; num++)
        arr[num] = arr[num - 1] + arr[num - 2];
}

int Fibonacci_Search(int arr[], const int length, int result) {
    int Fi[length], k = 0;
    Fibonacci(Fi, length);
    while (length > Fi[k]) k++;
    for (int num = length; num < Fi[k]; num++) arr[num] = arr[length - 1];
    int lower = 0, high = length - 1;
    while (lower <= high) {
        int middle = lower + Fi[k - 1];
        if (arr[middle] > result) {high = middle - 1;  k--;}
        else if (arr[middle] < result) {lower = middle + 1;  k -= 2;}
        else {
            if (middle >= length) return length - 1;
            return middle;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Locate: " << Fibonacci_Search(arr, length, 11) << endl;
    return 0;
}
