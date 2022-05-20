#include <iostream>
using namespace std;
#include <cmath>
#include <vector>
#include <unordered_map>

class Solution {
public:
    unordered_map<int, int> map;
    vector<int> result;
    int Max = 0;

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return vector<int>{-1};
        for (int num = 0; num < intervals.size(); num++) {
            map[intervals[num][0]] = num;
            Max = max(Max, intervals[num][0]);
        }
        for (int num = 0; num < intervals.size(); num++) {
            int middle = intervals[num][1];
            while (middle) {
                if (map[middle] != 0) result.push_back(map[middle]);
                else if (middle < Max) middle++;
                else {result.push_back(-1);  break;}
            }
        }
        return result;
    }
};

int main() {
    Solution matter;
    vector<vector<int>> intervals = {{3,4}, {2,3}, {1,2}};
    matter.findRightInterval(intervals);
    return 0;
}
