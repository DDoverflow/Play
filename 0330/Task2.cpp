#include <iostream>
using namespace std;

int Partition(int arr[], int front, int rear) {
    while (front < rear) {
        while (front < rear && arr[front] <= arr[rear]) rear--;
        if (front < rear) {
            int temp = arr[rear];
            arr[rear] = arr[front];
            arr[front] = temp;
        }
        while (front < rear && arr[front] <= arr[rear]) front++;
        if (front < rear) {
            int temp = arr[rear];
            arr[rear] = arr[front];
            arr[front] = temp;
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

void Merge(int arr[], int L, int M, int R) {
    int left_size = M - L, right_size = R - M + 1;
    int left[left_size], right[right_size];
    for (int k = L; k < M; k++) left[k - L] = arr[k];
    for (int k = M; k < R + 1; k++) right[k - M] = arr[k];
    int front = 0, rear = 0, k = L;
    while (front < left_size && rear < right_size) {
        if (left[front] > right[rear]) arr[k++] = right[rear++];
        else arr[k++] = left[front++];
    }
    while (front < left_size) arr[k++] = left[front++];
    while (rear < right_size) arr[k++] = right[rear++];
}

void Merge_Sort(int arr[], int L, int R) {
    if (L == R) return;
    int mid = (L + R) / 2;
    Merge_Sort(arr, L, mid);
    Merge_Sort(arr, mid + 1, R);
    Merge(arr, L, mid + 1, R);
}

int main() {
    int arr[] = {1,3,2,6,5,9,8,0,4,10,-4,-8,-1,-9,-3,-2,-6,-5,-7};
    int front = 0, rear = (sizeof(arr) / sizeof(arr[0])) - 1;
    Merge_Sort(arr, front, rear);
    cout << "arr: ";
    for (int k = 0; k < rear - front + 1; k++)
        cout << arr[k] << "  ";
    cout << endl;
    return 0;
}