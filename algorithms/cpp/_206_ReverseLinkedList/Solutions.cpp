#include <iostream>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        reverseUtil(&head, head, nullptr);
        return head;
    }

    void printList(ListNode *node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

private:
    void reverseUtil(ListNode **head, ListNode *curr, ListNode *prev) {
        if (!curr->next) {
            *head = curr;
            curr->next = prev;
            return;
        }
        ListNode *next = curr->next;
        curr->next = prev;
        reverseUtil(head, next, curr);
    }
};

int main() {
    auto *so = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    so->printList(l1);
    ListNode *res = so->reverseList(l1);
    so->printList(res);
    return 0;
}
