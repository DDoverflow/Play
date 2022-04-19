#include <iostream>
using namespace std;

void Move_prefix(int *prefix, int length) {
    for (int num = length - 1; num > 0; num--)
        prefix[num] = prefix[num - 1];
    prefix[0] = -1;
}

int *prefix_table(string code) {
    int *prefix = new int[code.length()];
    int current_len = 0, index = 1;
    prefix[current_len] = current_len;
    while (index < code.length()) {
        if (code[index] == code[current_len])
            prefix[index++] = ++current_len;
        else {
            if (current_len > 0)
                current_len = prefix[current_len - 1];
            else
                prefix[index++] = current_len;
        }
    }
    Move_prefix(prefix, code.length());
    return prefix;
}

int *simple_prefix_table(string code) {
    int *prefix = prefix_table(code), *simple_prefix = new int[code.length()];
    int index = 1;
    simple_prefix[0] = prefix[0];
    while (index < code.length()) {
        if (code[prefix[index]] == code[index])
            simple_prefix[index] = simple_prefix[prefix[index]];
        else
            simple_prefix[index] = prefix[index];
        index++;
    }
    return simple_prefix;
}

int Acquire(int *simple_prefix, int length, int result) {
    for (int num = 0; num < length; num++)
        if (simple_prefix[num] == result) return num;
}


void KMP(string contents, string code) {
    int *simple_prefix = simple_prefix_table(code);
    int front = 0, rear = 0;
    while (front < contents.length()) {
        if (rear == code.length() - 1 && contents[front] == code[rear]) {
            cout << "Find answer: " << front - rear << endl;
            int middle = simple_prefix[rear];
            if (middle == -1) rear = 0;
            else rear = Acquire(simple_prefix, code.length(), simple_prefix[middle]);
        }
        else if (rear == 0 && contents[front] != code[rear]) front++;
        else if (contents[front] == code[rear]) {front++;  rear++;}
        else {
            int middle = simple_prefix[rear];
            if (middle == -1) rear = 0;
            else rear = Acquire(simple_prefix, code.length(), simple_prefix[middle]);
        }
    }
}

void KMP(string contents, string code, int) {
    int *prefix = prefix_table(code);
    int front = 0, rear = 0;
    while (front < contents.length()) {
        if (rear == code.length() - 1 && contents[front] == code[rear]) {
            cout << "Find answer: " << front - rear << endl;
            rear = prefix[rear];
        }
        else if (rear == 0 && contents[front] != code[rear]) front++;
        else if (contents[front] == code[rear]) {front++;  rear++;}
        else rear = prefix[rear];
    }
}

int main() {
    string contents = "abcabcccababcabcabbaccabcbbabbac", code = "bba";
    KMP(contents, code);
    return 0;
}