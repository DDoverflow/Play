#include <iostream>
using namespace std;
#include <vector>

struct Node {
    int data;
    Node() {}
    Node(int data): data(data) {}
};

class Graph {
public:
    int length = 5, index = 0;
    struct Node **Vertex = new Node*[length];
    int **matrix = new int*[length];
    Graph();
    int Locate(int data);
    void Add_point(int data);
    void Add_side(int first, int second);
    void Show();
};

Graph::Graph() {
    for (int num = 0; num < length; num++) {
        matrix[num] = new int[length];
        for (int current = 0; current < length; current++) {
            if (num == current) matrix[num][current] = 0;
            else matrix[num][current] = -1;
        }
    }
}

int Graph::Locate(int data) {
    for (int num = 0; num < index; num++) {
        if (Vertex[num]->data == data) return num;
    }
    return -1;
}

void Graph::Add_point(int data) {
    if (index == length) {cout << "Vertex is full" << endl;  return;}
    struct Node *content = new Node(data);
    Vertex[index++] = content;
}

void Graph::Add_side(int first, int second) {
    int front = Locate(first), rear = Locate(second);
    if (front != -1 && rear != -1) {
        matrix[front][rear] = 1;
        matrix[rear][front] = matrix[front][rear];
    }
}

void Graph::Show() {
    for (int num1 = 0; num1 < length; num1++) {
        for (int num2 = 0; num2 < length; num2++)
            cout << matrix[num1][num2] << "\t";
        cout << endl;
    }
}

vector<int> color;

bool Estimate(int **matrix, int Locate, int ColorNum) {
    if (color.size() == 0) return true;
    for (int num = 0; num < color.size(); num++) {
        if (matrix[Locate][num] == 1 && color[num] == ColorNum) return false;
    }
    return true;
}

void BackTracking(int **matrix, int ColorNum, int count) {
    if (color.size() == count) {
        for (int num = 0; num < count; num++)
            cout << color[num] << "  ";
        cout << endl;
        return;
    }
    for (int num = 0; num < count; num++) {
        while (!Estimate(matrix, num, ColorNum)) ColorNum++;
        color.push_back(ColorNum);
        BackTracking(matrix, 1, count);
        color.pop_back();
    }
}

void MinColorNum(int **matrix, int count) {
    BackTracking(matrix, 1, count);
}

void Create_matrix() {
    Graph matter;
    for (int num = 0; num < 5; num++)
        matter.Add_point(num + 1);
    matter.Add_side(1, 2);  matter.Add_side(1, 3);
    matter.Add_side(2, 3);  matter.Add_side(2, 4);
    matter.Add_side(2, 5);  matter.Add_side(3, 5);
    matter.Add_side(4, 5);
    MinColorNum(matter.matrix, matter.length);
}

int main() {
    Create_matrix();
    return 0;
}