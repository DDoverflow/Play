#include <iostream>
using namespace std;

int Binary_Search(int arr[], int length, int result) {
    int front = 0, rear = length - 1;
    while (front <= rear) {
        int middle = (front + rear) / 2;
        if (arr[middle] > result) rear = middle - 1;
        else if (arr[middle] < result) front = middle + 1;
        else return middle;
    }
    return -1;
}

int main() {
    int arr[] = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Locate: " << Binary_Search(arr, length, 8) << endl;
    return 0;
}
