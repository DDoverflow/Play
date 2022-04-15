//
// Created by 陈智彬 on 2022/4/15.
//

#include <iostream>
#define len 9
#define max 65535
using namespace std;

// 使用方法：狄克斯特拉算法
// 算法思想：贪心算法(动态规划)


// 这里为了更方便寻找最短路径，把所有的 0 换成无穷大(65535)
int arr[len][len] = {{max,4,2,3,max,max,max,max,max},{max,max,max,max,9,8,max,max,max},{max,max,max,max,6,7,8,max,max},{max,max,max,max,max,4,7,max,max},{max,max,max,max,max,max,max,5,6},
{max,max,max,max,max,max,max,8,6},{max,max,max,max,max,max,max,6,5},{max,max,max,max,max,max,max,max,7},{max,max,max,max,max,max,max,max,3}};

void Dijkstra(int matter[len][len], const int length, int start) {  // 传入二维数组，节点个数和从哪个节点开始寻找
    int weight[length], parent[length];     // 设置一个权值数组和父类数组
    for (int k = 0; k < length; k++) {weight[k] = matter[start][k]; parent[k] = 0;}     // 把开始节点的那一栏数据传给 weight，并初始化每个节点父类为 0
    parent[start] = -1;
    while (true) {
        int lower_size = max, pos = -1;
        for (int k = 0; k < length; k++) {
            if (weight[k] != -1 && weight[k] < lower_size) {
                lower_size = weight[k];         // 寻找当前 weight 数组中权值最小的节点
                pos = k;
            }
        }
        if (pos == -1) break;
        for (int k = 0; k < length; k++) {      // 利用上面寻找到的节点来更新其他节点的权值
            if (weight[k] != -1 && weight[pos] + matter[pos][k] < weight[k]) {
                weight[k] = weight[pos] + matter[pos][k];
                parent[k] = pos;        // 如果更新成功就记录父类节点为该节点
            }
        }
        weight[pos] = -1;       // 标记该节点被使用过了
    }
    int last = length - 1, prev = parent[last];
    while (last != 0) {
        cout << last << "->";
        last = prev;
        prev = parent[prev];
        if (last == 0) {cout << last;  break;}      // 打印最短路径
    }
}

int main() {
    Dijkstra(arr, len, 0);  cout << endl;
    cout << "这里反向输出答案" << endl;
    return 0;
}
