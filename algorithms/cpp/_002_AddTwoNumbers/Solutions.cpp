#include <iostream>
#include <myListNode.h>

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;

        int sum = 0;
        int carry = 0;
        while (l1 || l2) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            sum = (carry + val1 + val2) % 10;
            carry = (carry + val1 + val2) / 10;
            prev->next = new ListNode(sum);
            prev = prev->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) prev->next = new ListNode(carry);
        return dummy->next;
    }
};

int main() {
//    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//    Output: 7 -> 0 -> 8
//    Explanation: 342 + 465 = 807.
    ListNode *l1 = createListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(6);

    ListNode *l2 = createListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    auto *so = new Solution();
    ListNode *res = so->addTwoNumbers(l1, l2);

    printList(l1);
    printList(l2);
    printList(res);
    delete l1;
    delete l2;
    delete res;
    delete so;
    return 0;
}