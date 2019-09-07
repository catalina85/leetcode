#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    44% test cases passedTotal runtime 3317 ms
public:
    int backPack(int m, vector<int> &A) {
        return helper(m, A, A.size());
    }

private:
    int helper(int m, vector<int> &A, int n) {
        if (m <= 0 || n == 0)
            return 0;
        if (m < A[n - 1])
            return helper(m, A, n - 1);
        return max(A[n - 1] + helper(m - A[n - 1], A, n - 1), helper(m, A, n - 1));
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 5, 7};
    int size = 12;
    int res = so->backPack(size, nums);
    cout << res << endl;
    delete so;
    return 0;
}
