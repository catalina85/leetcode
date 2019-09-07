#include <iostream>
#include <stack>
#include <myListNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        stack<int> s;

        while (fast != nullptr && fast->next != nullptr) {
            s.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }

        if (fast != nullptr)
            slow = slow->next;

        while (slow != nullptr) {
            if (slow->val != s.top())
                return false;
            slow = slow->next;
            s.pop();
        }
        return true;
    }
};

int main() {
    auto *so = new Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(1);
//    l1->next->next->next = new ListNode(4);
//    l1->next->next->next->next = new ListNode(5);
    bool res = so->isPalindrome(l1);
    print(res);
    return 0;
}
