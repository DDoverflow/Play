#include <iostream>
using namespace std;

int Binary_Search(int arr[], int length, int result) {
    int front = 0, rear = length - 1;
    while (front <= rear) {
        int mid = (front + rear) / 2;
        if (arr[mid] > result) rear = mid - 1;
        else if (arr[mid] < result) front = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    int arr[] = {1,3,5,7,9,11,13,15,17,19,21}, length = sizeof(arr) / sizeof(arr[0]);
    cout << "locate 11: " << Binary_Search(arr, length, 11) << endl;
    return 0;
}
