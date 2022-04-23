//
// Created by 陈智彬 on 2022/4/23.
//

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

