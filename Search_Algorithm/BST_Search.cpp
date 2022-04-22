#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

struct Tree {
    struct Node *root = nullptr;
};

void Create_BST(struct Tree *matter, int data) {
    struct Node *content = new Node;
    content->data = data;
    if (matter->root == nullptr) {matter->root = content;  return;}
    struct Node *middle = matter->root;
    while (middle) {
        if (data > middle->data) {
            if (middle->right != nullptr) middle = middle->right;
            else {middle->right = content;  return;}
        }
        else {
            if (middle->left != nullptr) middle = middle->left;
            else {middle->left = content;  return;}
        }
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
    int arr[] = {5,4,3,2,1,6,7,8,9,10}, length = sizeof(arr) / sizeof(arr[0]);
    for (int num = 0; num < length; num++)
        Create_BST(&matter, arr[num]);
    preorder(matter.root);  cout << endl;
    inorder(matter.root);   cout << endl;
    return 0;
}
