#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next = nullptr;
};

void Create_Node(int value) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = value;
    cout << "data: " << p->data << endl;
    free(p);
}

int main() {
    Create_Node(10);
    return 0;
}