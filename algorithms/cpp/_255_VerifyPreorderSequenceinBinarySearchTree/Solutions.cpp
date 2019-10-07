#include <iostream>
#include <vector>
#include <stack>
#include <myutils.h>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        int low = INT_MIN;
        stack<int> path;
        for (int p: preorder) {
            if (p < low)
                return false;
            while (!path.empty() && p > path.top()) {
                low = path.top();
                path.pop();
            }
            path.push(p);
        }
        return true;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> preorder{1, 3, 2};
    bool res = so->verifyPreorder(preorder);
    print(res);
    delete so;
    return 0;
}