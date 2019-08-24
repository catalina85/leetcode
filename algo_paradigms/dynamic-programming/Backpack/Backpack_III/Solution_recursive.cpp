#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    Time Limit Exceeded
//    46% test cases passed
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

private:
    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m <= 0 || len == 0)
            return 0;
        if (m >= A[len - 1])
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len), helper(m, A, V, len - 1));
        else
            return helper(m, A, V, len - 1);
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackIII(A, V, m);
    cout << res << endl;
    delete so;
    return 0;
}
