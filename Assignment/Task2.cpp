#include <iostream>
#include <vector>
using namespace std;

bool Separation(int arr[], int length) {
    int sum = 0;
    for (int num = 0; num < length; num++) sum += arr[num];
    vector<vector<int>> matter(length, vector<int>((sum / 2) + 1, 0));
    for (int num = arr[0]; num < sum / 2; num++) matter[0][num] = arr[0];
    for (int weight = 1; weight < length; weight++) {
        for (int space = 1; space < (sum / 2) + 1; space++) {
            if (space - arr[weight] < 0) matter[weight][space] = matter[weight - 1][space];
            else matter[weight][space] = max(matter[weight - 1][space], matter[weight - 1][space - arr[weight]] + arr[weight]);
        }
    }
    double result = sum / 2.0;
    return matter[length - 1][sum / 2] == result;
}

bool Separation(int arr[], int length, int sum) {
    for (int num = 0; num < length; num++) sum += arr[num];
    if (sum % 2 == 1) return false;
    vector<int> matter((sum / 2) + 1, 0);
    for (int weight = 0; weight < length; weight++) {
        for (int space = (sum / 2); space >= 0; space--) {
            if (space - arr[weight] >= 0)
                matter[space] = max(matter[space], matter[space - arr[weight]] + arr[weight]);
        }
    }
    double result = sum / 2.0;
    return matter[(sum / 2)] == result;
}

int main() {
    int arr[] = {1,5,11,5}, length = sizeof(arr) / sizeof(arr[0]);
    Separation(arr, length, 0);
    return 0;
}