#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;
        string res1 = "", res2 = "", result = "";
        while (l1 != nullptr) {
            res1 += to_string(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            res2 += to_string(l2->val);
            l2 = l2->next;
        }
        reverse(res1.begin(), res1.end());
        reverse(res2.begin(), res2.end());
        result += to_string(stoi(res1) + stoi(res2));
        reverse(result.begin(), result.end());
        for (int num = 0; num < result.length(); num++) {
            ListNode *middle = new ListNode(int(result[num]) - 48);
            if (head == nullptr) {
                head = middle;
                continue;
            }
            ListNode *current = head;
            while (current->next) current = current->next;
            current->next = middle;
        }
        while (head) {
            cout << head->val;
            head = head->next;
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(2);
    ListNode *l11 = new ListNode(4);
    ListNode *l12 = new ListNode(3);
    ListNode *l2 = new ListNode(5);
    ListNode *l21 = new ListNode(6);
    ListNode *l22 = new ListNode(4);
    Solution matter;
    l1->next = l11, l11->next = l12;
    l2->next = l21, l21->next = l22;
    matter.addTwoNumbers(l1, l2);
    return 0;
}