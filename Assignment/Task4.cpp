#include <iostream>
#include <vector>
#define bag_weight 4
using namespace std;

int Max_Price(vector<int> &contents, vector<int> &prices) {
    vector<vector<int>> matter(contents.size(), vector<int>(bag_weight + 1, 0));
    for (int num = contents[0]; num < bag_weight + 1; num++) matter[0][num] = prices[0];
    for (int content = 1; content < contents.size(); content++) {
        for (int current = 1; current < bag_weight + 1; current++) {
            if (current < contents[content]) matter[content][current] = matter[content - 1][current];
            else matter[content][current] = max(matter[content - 1][current], matter[content - 1][current - contents[content]] + prices[content]);
        }
    }
    return matter[contents.size() - 1][bag_weight];
}

int Max_Price(vector<int> &contents, vector<int> &prices, int) {
    vector<vector<int>> matter(contents.size(), vector<int>(bag_weight + 1, 0));
    for (int num = contents[0]; num < bag_weight + 1; num++) matter[0][num] = prices[0];
    for (int content = 1; content < contents.size(); content++) {
        for (int current = 1; current < bag_weight + 1; current++) {
            if (current - contents[content] >= 0)
                matter[content][current] = max(matter[content - 1][current], matter[content - 1][current - contents[content]] + prices[content]);
        }
    }
    return matter[contents.size() - 1][bag_weight];
}

int Optimize(vector<int> &weight, vector<int> &prices) {
    vector<int> matter(bag_weight + 1, 0);
    for (int cur_weight = 0; cur_weight < weight.size(); cur_weight++) {
        for (int locate = bag_weight; locate >= weight[cur_weight]; locate--)
            matter[locate] = max(matter[locate], matter[locate - weight[cur_weight]] + prices[cur_weight]);
    }
    for (int num1 = 0; num1 < bag_weight + 1; num1++)
        cout << matter[num1] << "  ";
    cout << endl;
//    return matter[bag_weight];
}

int Optimize(vector<int> &weight, vector<int> &prices, int) {
    vector<int> matter(bag_weight + 1, 0);
    for (int locate = bag_weight; locate >= 0; locate--) {
        for (int cur_weight = 0; cur_weight < weight.size(); cur_weight++)
            if (locate - weight[cur_weight] < 0) continue;
            else matter[locate] = max(matter[locate], matter[locate - weight[cur_weight]] + prices[cur_weight]);
    }
    for (int num1 = 0; num1 < bag_weight + 1; num1++)
        cout << matter[num1] << "  ";
    cout << endl;
}

int main() {
    vector<int> contents = {1,3,4};
    vector<int> prices = {15,20,30};
    return 0;
}
