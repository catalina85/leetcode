#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        return mergeHelper(lists, 0, lists.size() - 1);
    }

    ListNode *mergeHelper(vector<ListNode *> &lists, int start, int end) {
        if (start >= end)
            return lists[start];

        int mid = (end - start) / 2 + start;
        ListNode *left = mergeHelper(lists, start, mid);
        ListNode *right = mergeHelper(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        if (l1 == nullptr && l2 == nullptr)
            return nullptr;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                head->next = l2;
                break;
            }
            if (l2 == nullptr) {
                head->next = l1;
                break;
            }

            if (l1->val > l2->val) {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            } else {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
        }
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
    l1->next->next = new ListNode(4);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(5);
    l3->next->next = new ListNode(6);
    vector<ListNode *> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode *res = so->mergeKLists(lists);
    so->printList(res);
    delete so;
    return 0;
}
