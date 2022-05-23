#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
        for (int num = 0; num <= s.length(); num++) dp[num][0] = 1;
        for (int line = 1; line <= s.length(); line++) {
            for (int row = 1; row <= t.length(); row++) {
                if (s[line - 1] == t[row - 1]) dp[line][row] = dp[line - 1][row - 1] + dp[line - 1][row];
                else dp[line][row] = dp[line - 1][row];
            }
        }
        for (int num1 = 0; num1 <= s.length(); num1++) {
            for (int num2 = 0; num2 <= t.length(); num2++)
                cout << dp[num1][num2] << "  ";
            cout << endl;
        }
        return dp[s.length()][t.length()];
    }
};

/*
     b  a  g
  1  0  0  0
b 1  1  0  0
a 1  1  1  0
g 1  1  1  1  
g 1  1  1  2
 */

int main() {
    Solution matter;
    string s = "bagg", t = "bag";
    matter.numDistinct(s, t);
    return 0;
}
