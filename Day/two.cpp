#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution {
public:
    int Acquire_index(vector<int> &nums, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > target) end = mid - 1;
            else if (nums[mid] < target) start = mid + 1;
            else return mid;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int min_index = INT_MAX, max_index = 0;
        int current = Acquire_index(nums, 0, nums.size() - 1, target);
        cout << "current: " << current << endl;
        if (current == -1) return vector<int>{current, current};
        int left = current - 1, right = current + 1;
        for (int num = 0; num < nums.size(); num++) {
            left = Acquire_index(nums, 0, left, target);
            if (left != -1) {min_index = min(min_index, left);  left--;}
            else break;
        }
        for (int num = 0; num < nums.size(); num++) {
            right = Acquire_index(nums, right, nums.size() - 1, target);
            if (right != -1) {max_index = max(max_index, right);  right++;}
            else break;
        }
        if (min_index == INT_MAX && max_index == 0)
            return vector<int>{current, current};
        if (min_index != INT_MAX && max_index != 0)
            return vector<int>{min_index, max_index};
        if (min_index != INT_MAX) return vector<int>{min_index, current};
        if (max_index != 0) return vector<int>{current, max_index};
    }
};

int main() {
    Solution matter;
    vector<int> contents = {1,1,1,1,1,1,2,3,4,4,5,5,5,6,7,8,8,8,8};
    vector<int> result = matter.searchRange(contents, 8);
    cout << "{" << result[0] << ", " << result[1] << "}" << endl;
    return 0;
}
