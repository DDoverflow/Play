#include <iostream>
#include <vector>
using namespace std;

int BuyStock(vector<int> &prices) {
    vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
    dp[0][0] -= prices[0];  dp[1][0] = 0;
    for (int num = 1; num < prices.size(); num++) {
        dp[0][num] = max(dp[0][num - 1], -prices[num]);
        dp[1][num] = max(dp[1][num - 1], prices[num] + dp[0][num]);
    }
    for (int num = 0; num < prices.size(); num++)
        cout << dp[0][num] << "  ";
    cout << endl;
    for (int num = 0; num < prices.size(); num++)
        cout << dp[1][num] << "  ";
    cout << endl;
    return dp[1][prices.size() - 1];
}

int main() {
    vector<int> prices = {7,6,4,3,1};
    BuyStock(prices);
    return 0;
}