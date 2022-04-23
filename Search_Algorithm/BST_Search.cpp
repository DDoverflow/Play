#include <iostream>
#define LH 2
#define RH -2
#define EH 0
#define len 100
using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
};

struct Tree {
    struct Node *root = nullptr;
    struct Node **stack = new Node*[len];
    int index = 0;
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

void Delete_Node(struct Node **matter);
void Find_Node(struct Tree *matter, int data) {
    struct Node *middle = matter->root;
    while (middle) {
        if (middle->data == data) Delete_Node(&middle);
        else if (data > middle->data) middle = middle->right;
        else middle = middle->left;
    }
}

void Delete_Node(struct Node **matter) {
    struct Node *front, *rear;
    if ((*matter)->left == nullptr) {
        front = (*matter);
        (*matter) = (*matter)->right;
        delete front;
    }
    else if ((*matter)->right == nullptr) {
        front = (*matter);
        (*matter) = (*matter)->left;
        delete front;
    }
    else {
        front = (*matter), rear = (*matter)->left;
        while (rear->right) {
            front = rear;
            rear = rear->right;
        }
        (*matter)->data = rear->data;
        if (front != (*matter))
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

void test() {
    struct Tree matter;
    int arr[] = {12,5,18,2,9,15,19,17,16}, length = sizeof(arr) / sizeof(arr[0]);
    for (int num = 0; num < length; num++)
        Create_BST(&matter, arr[num]);
    Find_Node(&matter, 18);
    preorder(matter.root);  cout << endl;
    inorder(matter.root);   cout << endl;
}


int Acquire_depth(struct Node *matter, int count = 1) {
    if (matter == nullptr) return 0;
    if (matter->left == nullptr && matter->right == nullptr) return 1;
    int left_depth = Acquire_depth(matter->left, count + 1);
    int right_depth = Acquire_depth(matter->right, count + 1);
    if (count == 1) return left_depth - right_depth;
    if (left_depth && right_depth) return max(left_depth, right_depth) + 1;
    else if (left_depth) return left_depth + 1;
    else return right_depth + 1;
}


void Right_rotate(struct Node **matter) {
    struct Node *middle = (*matter)->left;
    (*matter)->left = middle->right;
    middle->right = (*matter);
    (*matter) = middle;
}

void Left_rotate(struct Node **matter) {
    struct Node *middle = (*matter)->right;
    (*matter)->right = middle->left;
    middle->left = (*matter);
    (*matter) = middle;
}

void Left_Balance(struct Node **matter) {
    struct Node *middle = (*matter)->left;
    switch (Acquire_depth(middle)) {
        case LH - 1: {Right_rotate(matter);  break;}
        case RH + 1: {
            Left_rotate(&middle);
            Right_rotate(matter);
        }
    }
}

void Right_Balance(struct Node **matter) {
    struct Node *middle = (*matter)->right;
    switch (Acquire_depth(middle)) {
        case RH + 1: {Left_rotate(matter);  break;}
        case LH - 1: {
            Right_rotate(&middle);
            Left_rotate(matter);
        }
    }
}

// 注意：如果你要修改指针的指向，那么就必须直接处理一维指针的地址，不能用中间指针去保存，然后把中间指针放入数组中
// 如果你把保存一维指针的中间指针放入数组中，然后提取出来交换是无法修改指向的
// 因为此时你提取出来的一维指针(这里是中间指针)就是一个副本，只能修改一维指针的值，无法修改指向
void Create_AVL(struct Node **matter, int data) {
    struct Node *middle = new Node;
    middle->data = data;
    if ((*matter) == nullptr) {(*matter) = middle;  return;}
    if (data > (*matter)->data) {
        if ((*matter)->right == nullptr) (*matter)->right = middle;
        else Create_AVL(&(*matter)->right, data);
    }
    else {
        if ((*matter)->left == nullptr) (*matter)->left = middle;
        else Create_AVL(&(*matter)->left, data);
    }
    if (Acquire_depth((*matter)) == LH) Left_Balance(matter);
    else if (Acquire_depth((*matter)) == RH) Right_Balance(matter);
}

void test1() {
    struct Tree *matter = new Tree;
    int arr[] = {}, length = sizeof(arr) / sizeof(arr[0]);
    for (int num = 0; num < length; num++)
        Create_AVL(&matter->root, arr[num]);
    preorder(matter->root);  cout << endl;
    inorder(matter->root);   cout << endl;
}

int main() {
    test1();
    return 0;
}
