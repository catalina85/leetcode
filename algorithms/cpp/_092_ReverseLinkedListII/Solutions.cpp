#include <iostream>
#include <stack>
#include <myListNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m >= n)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        for (int i = 1; i < m; i++) {
            head = head->next;
        }

        ListNode *premNode = head;
        ListNode *mNode = head->next;
        ListNode *nNode = mNode;
        ListNode *postnNode = mNode->next;
        for (int i = m; i < n; i++) {
            ListNode *temp = postnNode->next;
            postnNode->next = nNode;
            nNode = postnNode;
            postnNode = temp;
        }

        mNode->next = postnNode;
        premNode->next = nNode;
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
    int m = 2, n = 4;
    printList(l1);
    ListNode *res = so->reverseBetween(l1, m, n);
    printList(res);
    return 0;
}
