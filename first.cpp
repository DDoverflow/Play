#include <iostream>
#define line 2
#define row 3
using namespace std;

struct Node {           // 定义一个 Node 类，里面存放二维数组
    int matrix[line][row];
};

Node &operator+(struct Node &matter1, struct Node &matter2) {   // 重载 + 运算符，使两个 Node 对象可以直接相加
    for (int i = 0; i < line; i++) {
        for (int k = 0; k < row; k++)
            matter1.matrix[i][k] += matter2.matrix[i][k];       // 让 matter2 的元素可以加入 matter1 中
    }
    return matter1;
}

istream &operator>>(istream &input, struct Node &matter) {
    for (int i = 0; i < line; i++) {
        for (int k = 0; k < row; k++)
            input >> matter.matrix[i][k];
    }
}

ostream &operator<<(ostream &output, struct Node &matter) {
    for (int i = 0; i < line; i++) {
        for (int k = 0; k < row; k++)
            output << matter.matrix[i][k] << "  ";
        cout << endl;
    }
}

int main() {
    struct Node matter1, matter2;
    cin >> matter1 >> matter2;
    struct Node middle = matter1 + matter2;
    cout << middle;
    return 0;
}