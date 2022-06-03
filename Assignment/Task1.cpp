#include <iostream>
#include <vector>
using namespace std;

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

void Create_BST(struct Tree *tree, int data) {
    struct Node *Addition = new Node(data);
    if (tree->root == nullptr) {tree->root = Addition;  return;}
    struct Node *middle = tree->root;
    while (middle != nullptr) {
        if (data >= middle->data) {
            if (middle->right != nullptr) middle = middle->right;
            else {middle->right = Addition;  return;}
        }
        else {
            if (middle->left != nullptr) middle = middle->left;
            else {middle->left = Addition;  return;}
        }
    }
}

void DeleteNode(struct Node *&matter) {
    struct Node *front = matter, *rear;
    if (matter->left == nullptr) {
        matter = matter->left;
        delete front;
    }
    else if (matter->right == nullptr) {
        matter = matter->left;
        delete front;
    }
    else {
        rear = matter->left;
        while (rear->right != nullptr) {
            front = rear;
            rear = rear->right;
        }
        matter->data = rear->data;
        if (front == matter) front->left = rear->left;
        else front->right = rear->left;
        delete rear;
    }
}

void FindNode(struct Node *&matter, int data) {
    if (matter == nullptr) return;
    if (data > matter->data) FindNode(matter->right, data);
    else if (data < matter->data) FindNode(matter->left, data);
    else DeleteNode(matter);
}

void Preorder(struct Node *root) {
    if (root != nullptr) {
        cout << root->data << "  ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Inorder(struct Node *root) {
    if (root != nullptr) {
        Inorder(root->left);
        cout << root->data << "  ";
        Inorder(root->right);
    }
}

int main() {
    struct Tree *matter = new Tree;
    vector<int> contents = {5,3,6,2,4,7};
    for (int num = 0; num < contents.size(); num++)
        Create_BST(matter, contents[num]);
    FindNode(matter->root, 7);
    Preorder(matter->root);  cout << endl;
    Inorder(matter->root);  cout << endl;
    return 0;
}