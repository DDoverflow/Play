#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) return false;
        unordered_map<char, int> map;
        for (int num = 0; num < magazine.length(); num++) map[magazine[num]]++;
        for (int num = 0; num < ransomNote.length(); num++) {
            if (map.find(ransomNote[num]) == map.end()) return false;
            map[ransomNote[num]]--;
            if (map[ransomNote[num]] == 0) map.erase(ransomNote[num]);
        }
        return true;
    }
};

int main() {
    Solution matter;
    string ransomNode = "aa", magazine = "ab";
    cout << "consist: " << matter.canConstruct(ransomNode, magazine) << endl;
    return 0;
}