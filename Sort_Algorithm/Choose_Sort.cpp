#include <iostream>
using namespace std;

void Choose_Sort(int arr[], int length) {
    for (int num = length - 1; num >= 0; num--) {
        int max_data = arr[num], pos = num;
        for (int current = 0; current <= num; current++) {
            if (arr[current] > max_data) {
                max_data = arr[current];
                pos = current;
            }
        }
        int temp = arr[num];
        arr[num] = arr[pos];
        arr[pos] = temp;
    }
}

int main() {
    int arr[] = {10,9,8,7,6,5,4,3,2,1}, length = sizeof(arr) / sizeof(arr[0]);
    Choose_Sort(arr, length);
    for (int num = 0; num < length; num++)
        cout << arr[num] << "  ";
    cout << endl;
    return 0;
}
