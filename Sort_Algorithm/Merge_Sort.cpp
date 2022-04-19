#include <iostream>
using namespace std;

void Merge(int arr[], int front, int mid, int rear) {
    int left_size = mid - front + 1, right_size = rear - mid;
    int left[left_size], right[right_size];
    for (int num = front; num < mid + 1; num++)
        left[num - front] = arr[num];
    for (int num = mid + 1; num < rear + 1; num++)
        right[num - mid - 1] = arr[num];
    int lc = 0, rc = 0, cur = front;
    while (lc < left_size && rc < right_size) {
        if (left[lc] > right[rc])
            arr[cur++] = right[rc++];
        else
            arr[cur++] = left[lc++];
    }
    while (lc < left_size)
        arr[cur++] = left[lc++];
    while (rc < right_size)
        arr[cur++] = right[rc++];
}

void Merge_Sort(int arr[], int front, int rear) {
    if (front == rear) return;
    int mid = (front + rear) / 2;
    Merge_Sort(arr, front, mid);
    Merge_Sort(arr, mid + 1, rear);
    Merge(arr, front, mid, rear);
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}, length = sizeof(arr) / sizeof(arr[0]);
    Merge_Sort(arr, 0, length - 1);
    for (int num = 0; num < length; num++)
        cout << arr[num] << "  ";
    cout << endl;
    return 0;
}
