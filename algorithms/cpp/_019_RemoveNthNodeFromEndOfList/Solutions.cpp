#include <iostream>
#include <myListNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        for (int i = 1; i <= n; i++)
            first = first->next;

        while (first->next) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
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

    ListNode *res = so->removeNthFromEnd(l1, 2);
    printList(res);
    delete res;
    delete so;
    return 0;
}
