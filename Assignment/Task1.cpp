#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void Swap(vector<int> &nums, int left, int right) {
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}

	int Partition(vector<int> &nums, int front, int rear) {
		while (front < rear) {
			while (front < rear && nums[front] <= nums[rear]) rear--;
			if (front < rear) Swap(nums, front, rear);
			while (front < rear && nums[front] < nums[rear]) front++;
			if (front < rear) Swap(nums, front, rear);
		}
		return front;
	}

	void QuickSort(vector<int> &nums, int front, int rear) {
		if (front >= rear) return;
		int middle = Partition(nums, front, rear);
        QuickSort(nums, front, middle - 1);
        QuickSort(nums, middle + 1, rear);
	}
};

int main() {
	string a = "abc", b = "abc";
	cout << "Equal: " << (a == b) << endl;
	return 0;
}