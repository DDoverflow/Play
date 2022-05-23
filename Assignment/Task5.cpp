#include <iostream>
#define LH 2
#define RH -2
using namespace std;
#include <vector>

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node() {}
    Node(int data): data(data) {}
};

struct Tree {
    struct Node *root = nullptr;
};

int Acquire_BF(struct Node *&matter, int count = 1) {
    if (matter == nullptr) return 0;
    if (matter->left == nullptr && matter->right == nullptr) return 1;
    int left = Acquire_BF(matter->left, count + 1);
    int right = Acquire_BF(matter->right, count + 1);
    if (count == 1) return left - right;
    return max(left, right) + 1;
}

void Left_rotate(struct Node *&matter) {
    struct Node *matter_right = matter->right;
    matter->right = matter_right->left;
    matter_right->left = matter;
    matter = matter_right;
}

void Right_rotate(struct Node *&matter) {
    struct Node *matter_left = matter->left;
    matter->left = matter_left->right;
    matter_left->right = matter;
    matter = matter_left;
}

void Left_balance(struct Node *&matter) {
    struct Node *matter_left = matter->left;
    switch (Acquire_BF(matter_left)) {
        case LH - 1: {Right_rotate(matter);  break;}
        case RH + 1: {Left_rotate(matter->left);  Right_rotate(matter);  break;}
    }
}

void Right_balance(struct Node *&matter) {
    struct Node *matter_right = matter->right;
    switch (Acquire_BF(matter_right)) {
        case LH - 1: {Right_rotate(matter->right);  Left_rotate(matter);  break;}
        case RH + 1: {Left_rotate(matter);  break;}
    }
}

void Create_AVL(struct Node *&matter, int data) {
    if (matter == nullptr) {
        struct Node *contents = new Node(data);
        matter = contents;
        return;
    }
    if (data >= matter->data) Create_AVL(matter->right, data);
    else Create_AVL(matter->left, data);
    if (Acquire_BF(matter) == LH) Left_balance(matter);
    else if (Acquire_BF(matter) == RH) Right_balance(matter);
}

void Preorder(struct Node *matter) {
    if (matter != nullptr) {
        cout << matter->data << "  ";
        Preorder(matter->left);
        Preorder(matter->right);
    }
}

void Inorder(struct Node *matter) {
    if (matter != nullptr) {
        Inorder(matter->left);
        cout << matter->data << "  ";
        Inorder(matter->right);
    }
}

int main() {
    struct Tree matter;
    vector<int> contents = {4,1,6,0,2,5,7,3,8};
    for (int num = 0; num < contents.size(); num++)
        Create_AVL(matter.root, contents[num]);
    Preorder(matter.root);  cout << endl;
    Inorder(matter.root);   cout << endl;
    return 0;
}