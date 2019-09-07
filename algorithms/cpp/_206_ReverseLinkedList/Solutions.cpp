#include <iostream>
#include <stack>
#include <myListNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr)
            return nullptr;

        reverseUtil(&head, head, nullptr);
        return head;
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
    printList(l1);
    ListNode *res = so->reverseList(l1);
    printList(res);
    return 0;
}
