#include <iostream>
using namespace std;

int Partition(int arr[], int front, int rear) {
    while (front < rear) {
        while (front < rear && arr[front] < arr[rear]) rear--;
        if (front < rear) {
            int temp = arr[front];
            arr[front] = arr[rear];
            arr[rear] = temp;
        }
        while (front < rear && arr[front] < arr[rear]) front++;
        if (front < rear) {
            int temp = arr[front];
            arr[front] = arr[rear];
            arr[rear] = temp;
        }
    }
    return front;
}

void Quick_Sort(int arr[], int front, int rear) {
    if (front < rear) {
        int middle = Partition(arr, front, rear);
        Quick_Sort(arr, front, middle - 1);
        Quick_Sort(arr, middle + 1, rear);
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}, length = sizeof(arr) / sizeof(arr[0]);
    Quick_Sort(arr, 0, length - 1);
    for (int num = 0; num < length; num++)
        cout << arr[num] << "  ";
    cout << endl;
    return 0;
}
