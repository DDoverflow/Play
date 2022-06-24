#include <iostream>
#include <vector>
#include <climits>
#include <valarray>

using namespace std;

struct Node {
    int start, end, weight;
    Node() {}
    Node(int start, int end, int weight): start(start), end(end), weight(weight) {}
};

struct Node *Change(vector<vector<int>> &contents) {
    struct Node *Edge = new Node();
    int index = 0;
    for (int num1 = 0; num1 < contents.size(); num1++) {
        for (int num2 = num1; num2 < contents[0].size(); num2++) {
            if (contents[num1][num2] != INT_MAX) {
                Edge[index].start = num1;
                Edge[index].end = num2;
                Edge[index].weight = contents[num1][num2];
                index++;
            }
        }
    }
    for (int num1 = 0; num1 < index - 1; num1++) {
        for (int num2 = 0; num2 < index - 1 - num1; num2++) {
            if (Edge[num2].weight > Edge[num2 + 1].weight) {
                struct Node temp = Edge[num2];
                Edge[num2] = Edge[num2 + 1];
                Edge[num2 + 1] = temp;
            }
        }
    }
    return Edge;
}

int Cycle(vector<int> &parent, int index) {
    while (parent[index] > 0)
        index = parent[index];
    return index;
}

void Kruskal(struct Node *content, vector<vector<int>> &matrix, int length) {
    vector<int> parent(matrix.size(), 0);
    int count = 0;
    for (int num = 0; num < length; num++) {
        int front = Cycle(parent, content[num].start);
        int rear = Cycle(parent, content[num].end);
        if (front != rear) {
            parent[front] = rear;
            cout << front + 1 << "->" << rear + 1 << ": " << content[num].weight << endl;
            count++;
            if (count == matrix.size() - 1) break;
        }
    }
    cout << "end" << endl;
}

int main() {
    vector<vector<int>> matrix = {
            {INT_MAX,6,1,5,INT_MAX,INT_MAX},
            {6,INT_MAX,5,INT_MAX,3,INT_MAX},
            {1,5,INT_MAX,5,6,4},
            {5,INT_MAX,5,INT_MAX,INT_MAX,2},
            {INT_MAX,3,6,INT_MAX,INT_MAX,6},
            {INT_MAX,INT_MAX,4,2,6,INT_MAX}
    };
    struct Node *content = Change(matrix);
    Kruskal(content, matrix, pow(matrix.size(), 2) / 2);
    return 0;
}
