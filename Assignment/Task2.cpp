#include <iostream>
#include <vector>
#include <stack>

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

struct Node* CreateBinaryTree(struct Tree *tree, vector<int> &contents) {
    vector<struct Node*> result(contents.size(), nullptr);
    for (int number = 0; number < contents.size(); number++) {
        if (contents[number] == -1) continue;
        struct Node *Content = new Node(contents[number]);
        result[number] = Content;
    }
    tree->root = result[0];
    for (int current = 0; current < result.size(); current++) {
        if (current * 2 + 1 < result.size()) result[current]->left = result[current * 2 + 1];
        else break;
        result[current]->right = result[current * 2 + 2];
    }
    return tree->root;
}

void Preorder(struct Node *content) {
    if (content != nullptr) {
        cout << content->data << "  ";
        Preorder(content->left);
        Preorder(content->right);
    }
}

void Inorder(struct Node *content) {
    if (content != nullptr) {
        Inorder(content->left);
        cout << content->data << "  ";
        Inorder(content->right);
    }
}

void Preorder(struct Node *root, vector<int> &result) {
    stack<struct Node *> Stack;
    if (root == nullptr) return;
    Stack.push(root);
    while (!Stack.empty()) {
        struct Node *content = Stack.top();
        Stack.pop();
        result.push_back(content->data);
        if (content->right) Stack.push(content->right);
        if (content->left) Stack.push(content->left);
    }
}

void Inorder(struct Node *root, vector<int> &result) {
    stack<struct Node *> Stack;
    if (root == nullptr) return;
    while (root != nullptr || !Stack.empty()) {
        if (root != nullptr) {
            Stack.push(root);
            root = root->left;
        }
        else {
            root = Stack.top();
            Stack.pop();
            result.push_back(root->data);
            root = root->right;
        }
    }
}

void Postorder(struct Node *root, vector<int> &result) {
    stack<struct Node *> Stack;
    if (root == nullptr) return;
    Stack.push(root);
    while (!Stack.empty()) {
        struct Node *content = Stack.top();
        Stack.pop();
        result.push_back(content->data);
        if (content->left) Stack.push(content->left);
        if (content->right) Stack.push(content->right);
    }
    reverse(result.begin(), result.end());
}

int main() {
    struct Tree *tree = new Tree;
    vector<int> contents = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    CreateBinaryTree(tree, contents);
    vector<int> result;
    Postorder(tree->root, result);
    for (int num = 0; num < result.size(); num++)
        cout << result[num] << "  ";
    cout << endl;
    return 0;
}

// 4  1  0  2  3  6  5  7  8