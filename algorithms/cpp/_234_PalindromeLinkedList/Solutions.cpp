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
    cout << res << endl;
    return 0;
}
