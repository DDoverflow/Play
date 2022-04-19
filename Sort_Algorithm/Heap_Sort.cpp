#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

struct Tree {
    struct Node *root = nullptr;
};

void Swap(int arr[], int front, int rear) {
    int temp = arr[front];
    arr[front] = arr[rear];
    arr[rear] = temp;
}

void Heapify(int arr[], int count, int index) {
    if (index >= count) return;
    int left_child = index * 2 + 1, right_child = index * 2 + 2, max = index;
    if (left_child < count && arr[max] < arr[left_child]) max = left_child;
    if (right_child < count && arr[max] < arr[right_child]) max = right_child;
    if (max != index) {
        Swap(arr, max, index);
        Heapify(arr, count, max);
    }
}

void Build_Heap(int arr[], int count) {
    int last_node = ((count - 1) - 1) / 2;
    for (int num = last_node; num >= 0; num--)
        Heapify(arr, count, num);
}

void Exhibition(int arr[], int count) {
    Build_Heap(arr, count);
    for (int num = count - 1; num >= 0; num--) {
        Swap(arr, num, 0);
        Heapify(arr, num, 0);
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0}, count = sizeof(arr) / sizeof(arr[0]);
    Exhibition(arr, count);
    for (int num = 0; num < count; num++)
        cout << arr[num] << "  ";
    cout << endl;
    return 0;
}
