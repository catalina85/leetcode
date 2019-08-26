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

    void printList(ListNode *node) {
        while (node != NULL) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
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
    so->printList(l1);
    ListNode *res = so->reverseBetween(l1, m, n);
    so->printList(res);
    return 0;
}
