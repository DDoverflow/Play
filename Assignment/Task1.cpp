#include <iostream>
#include <vector>
using namespace std;

int Max_price(int weight[], int prices[], int len1) {
    int max_weight = 0;
    for (int num = 0; num < len1; num++) if (max_weight < weight[num]) max_weight = weight[num];
    vector<vector<int>> matter(len1 + 1, vector<int>(max_weight + 1, 0));
    for (int num1 = 1; num1 < len1 + 1; num1++) {
        for (int num2 = 1; num2 < max_weight + 1; num2++) {
            if (num2 < weight[num1 - 1]) matter[num1][num2] = matter[num1 - 1][num2];
            else matter[num1][num2] = max(matter[num1 - 1][num2], matter[num1 - 1][num2 - weight[num1 - 1]] + prices[num1 - 1]);
        }
    }
    for (int num1 = 0; num1 < len1 + 1; num1++) {
        for (int num2 = 0; num2 < max_weight + 1; num2++)
            cout << matter[num1][num2] << "  ";
        cout << endl;
    }
    return 1;
}


int Max_price(vector<int> &weight, vector<int> &prices) {
    int max_weight = 0;
    for (int num = 0; num < weight.size(); num++) if (max_weight < weight[num]) max_weight = weight[num];
    vector<int> dp(max_weight + 1, 0);
    for (int num1 = 0; num1 < weight.size(); num1++) {
        for (int num2 = max_weight; num2 >= weight[num1]; num2--) {
            dp[num2] = max(dp[num2], dp[num2 - weight[num1]] + prices[num1]);
        }
    }
    return dp[max_weight];
}

void Complete_pack(vector<int> &weight, vector<int> &prices, int) {
    int max_weight = 0;
    for (int num = 0; num < weight.size(); num++) if (max_weight < weight[num]) max_weight = weight[num];
    vector<int> dp(max_weight + 1, 0);
    for (int num1 = 0; num1 < weight.size(); num1++) {
        for (int num2 = weight[num1]; num2 < max_weight + 1; num2++) {
            dp[num2] = max(dp[num2], dp[num2 - weight[num1]] + prices[num1]);
        }
    }
    for (int num = 0; num < max_weight + 1; num++)
        cout << dp[num] << "  ";
    cout << endl;
}


void Complete_pack(vector<int> &weight, vector<int> &prices) {
    int max_weight = 0;
    for (int num = 0; num < weight.size(); num++) if (max_weight < weight[num]) max_weight = weight[num];
    vector<vector<int>> dp(weight.size(), vector<int>(max_weight + 1, 0));
    for (int num = weight[0]; num < max_weight + 1; num++) dp[0][num] = prices[0] * int(num / weight[0]);
    for (int num2 = 1; num2 < max_weight + 1; num2++) {
        for (int num1 = 1; num1 < weight.size(); num1++) {
            if (num2 < weight[num1]) dp[num1][num2] = dp[num1 - 1][num2];
            else dp[num1][num2] = max(dp[num1 - 1][num2], dp[num1 - 1][num2 - weight[num1]] + prices[num1]);
        }
    }
    for (int num1 = 0; num1 < weight.size(); num1++) {
        for (int num2 = 0; num2 < max_weight + 1; num2++)
            cout << dp[num1][num2] << "  ";
        cout << endl;
    }
}

int main() {
    vector<int> weight = {1,3,4}, prices = {15,20,30};
    Complete_pack(weight, prices); cout << endl;
    Complete_pack(weight, prices, 10);
    return 0;
}