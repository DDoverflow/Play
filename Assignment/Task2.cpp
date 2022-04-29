#include <iostream>
#include <vector>
#define LH 2
#define RH -2
using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int data): data(data) {}
};

struct Tree {
    struct Node *root = nullptr;
};

// AVL

int Acquire_BF(struct Node *&matter, int count = 1) {
    if (matter == nullptr) return 0;
    if (matter->left == nullptr && matter->right == nullptr) return 1;
    int left_depth = Acquire_BF(matter->left, count + 1);
    int right_depth = Acquire_BF(matter->right, count + 1);
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
    switch (Acquire_BF(middle)) {
        case LH - 1: {Right_rotate(matter);  break;}
        case RH + 1: {Left_rotate(matter->left);  Right_rotate(matter);  break;}
    }
}

void Right_Balance(struct Node *&matter) {
    struct Node *middle = matter->right;
    switch (Acquire_BF(middle)) {
        case LH - 1: {Right_rotate(matter->right);  Left_rotate(matter);  break;}
        case RH + 1: {Left_rotate(matter);  break;}
    }
}

void Create_AVL(struct Node *&matter, int data) {
    struct Node *content = new Node(data);
    if (matter == nullptr) {matter = content;  return;}
    if (data >= matter->data)
        Create_AVL(matter->right, data);
    else if (data < matter->data)
        Create_AVL(matter->left, data);
    if (Acquire_BF(matter) == LH) Left_Balance(matter);
    else if (Acquire_BF(matter) == RH) Right_Balance(matter);
}

// Search

int Find_vertex(struct Node *matter, int result, int count = 1) {
    if (matter == nullptr) return 0;
    if (matter->data == result) return count;
    if (result > matter->data) return Find_vertex(matter->right, result, count + 1);
    else if (result < matter->data) return Find_vertex(matter->left, result, count + 1);
}

// Delete

Node *&Search_vertex(struct Node *&matter, int result) {
    if (result == matter->data) return matter;
    if (result > matter->data) return Search_vertex(matter->right, result);
    return Search_vertex(matter->left, result);
}

void Delete_vertex(struct Node *&matter, int result) {
    struct Node *&contents = Search_vertex(matter, result);
    struct Node *front, *rear;
    if (contents->left == nullptr) {
        front = contents;
        contents = contents->right;
        delete front;
    }
    else if (contents->right == nullptr) {
        front = contents;
        contents = contents->left;
        delete front;
    }
    else {
        front = contents;
        rear = front->left;
        while (rear->right != nullptr) {
            front = rear;
            rear = rear->right;
        }
        contents->data = rear->data;
        if (front != contents)
            front->right = rear->left;
        else
            front->left = rear->left;
        delete rear;
    }
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

int main() {
    struct Tree matter;
    vector<int> contents = {1,2,3,4,5,6,7,9,10};
    for (int num = 0; num < contents.size(); num++)
        Create_AVL(matter.root, contents[num]);
    preorder(matter.root);  cout << endl;
    inorder(matter.root);   cout << endl;
    return 0;
}