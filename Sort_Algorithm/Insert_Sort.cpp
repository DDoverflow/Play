#include <iostream>
using namespace std;

void Insert_Sort(int arr[], int length) {
    for (int num = 1; num < length; num++) {
        int key = arr[num], pos = num;
        while (arr[num - 1] > key) {
            arr[num] = arr[num - 1];
            num--;
            if (num == 0) break;
        }
        arr[num] = key;
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1}, length = sizeof(arr) / sizeof(arr[0]);
    Insert_Sort(arr, length);
    for (int num = 0; num < length; num++)
        cout << arr[num] << "  ";
    cout << endl;
    return 0;
}
