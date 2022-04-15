//
// Created by 陈智彬 on 2022/4/15.
//

#include <iostream>
using namespace std;

void Swap(int arr[], int front, int rear) {
    int temp = arr[front];
    arr[front] = arr[rear];
    arr[rear] = temp;
}

void Heapify(int arr[], int index, int count) {
    if (index >= count) {cout << "index 超出边界了" << endl;  return;}
    int left_index = 2 * index + 1, right_index = 2 * index + 2, max = index;
    if (left_index < count && arr[max] < arr[left_index]) max = left_index;
    if (right_index < count && arr[max] < arr[right_index]) max = right_index;
    if (max != index) {
        Swap(arr, max, index);
        Heapify(arr, max, count);
    }
}

void Build_Heap(int arr[], int count) {
    int index = ((count - 1) - 1) / 2;
    for (int k = index; k >= 0; k--)
        Heapify(arr, k, count);
}

int main() {
    int arr[] = {1,4,3,2,5,6,8,9,0}, length = sizeof(arr) / sizeof(arr[0]);
    Build_Heap(arr, length);
    for (int k = 0; k < length; k++)
        cout << arr[k] << "  ";
    cout << endl;
    return 0;
}