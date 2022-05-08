#include <iostream>
#define LH 2
#define RH -2
using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int data): data(data) {}
    Node() {}
};

struct Tree {
    struct Node *root = nullptr;
};

int Acquire_depth(struct Node *&matter, int count = 1) {
    if (matter == nullptr) return 0;
    if (matter->left == nullptr && matter->right == nullptr) return 1;
    int left_depth = Acquire_depth(matter->left, count + 1);
    int right_depth = Acquire_depth(matter->right, count + 1);
    if (count == 1) return left_depth - right_depth;
    if (left_depth && right_depth) return max(left_depth, right_depth) + 1;
    else if (left_depth) return left_depth + 1;
    else return right_depth + 1;
}

void Right_rotate(struct Node *&matter) {
    struct Node *middle = matter->left;
    matter->left = middle->right;
    middle->right = matter;
    matter = middle;
}

void Left_rotate(struct Node *&matter) {
    struct Node *middle = matter->right;
    matter->right = middle->left;
    middle->left = matter;
    matter = middle;
}

void Left_Balance(struct Node *&matter) {
    struct Node *middle = matter->left;
    switch (Acquire_depth(middle)) {
        case LH - 1: {Right_rotate(matter);  break;}
        case RH + 1: {Left_rotate(matter->left);  Right_rotate(matter);  break;}
    }
}

void Right_Balance(struct Node *&matter) {
    struct Node *middle = matter->right;
    switch (Acquire_depth(middle)) {
        case RH + 1: {Left_rotate(matter);  break;}
        case LH - 1: {Right_rotate(matter->right);  Left_rotate(matter);  break;}
    }
}

void Create_AVL(struct Node *&matter, int data) {
    struct Node *New = new Node(data);
    if (matter == nullptr) {matter = New;  return;}
    if (data >= matter->data) Create_AVL(matter->right, data);
    else Create_AVL(matter->left, data);
    if (Acquire_depth(matter) == LH) Left_Balance(matter);
    else if (Acquire_depth(matter) == RH) Right_Balance(matter);
}

void preorder(struct Node *matter) {
    if (matter != nullptr) {
        cout << matter->data << "  ";
        preorder(matter->left);
        preorder(matter->right);
    }
}

void inorder(struct Node *matter) {
    if (matter != nullptr) {
        inorder(matter->left);
        cout << matter->data << "  ";
        inorder(matter->right);
    }
}

void test() {
    struct Tree tree;
    int arr[] = {1,2,3,4,5,6,7,8,9,10}, length = sizeof(arr) / sizeof(arr[0]);
    for (int num = 0; num < length; num++)
        Create_AVL(tree.root, arr[num]);
    preorder(tree.root);  cout << endl;
    inorder(tree.root);   cout << endl;
}

int main() {
    test();
    return 0;
}