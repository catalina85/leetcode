#include <iostream>
#include <vector>
#include <stack>
#include <myutils.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> stk;
        int m = pushed.size();
        int n = popped.size();
        if (m != n)
            return false;
        int j = 0;
        for (int x:pushed) {
            stk.push(x);
            while (!stk.empty() && j < m && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return j == m;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};
    bool res = so->validateStackSequences(pushed, popped);
    print(res);
    delete so;
    return 0;
}
