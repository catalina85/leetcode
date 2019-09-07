#include <iostream>
#include <vector>

using namespace std;

class SolutionRecursion {
//    36% test cases passedTotal runtime 1104 ms
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int len = A.size();
        return helper(m, A, V, len);
    }

private:
    int helper(int m, vector<int> &A, vector<int> &V, int len) {
        if (m == 0 || len == 0)
            return 0;
        if (m < A[len - 1])
            return helper(m, A, V, len - 1);
        else
            return max(V[len - 1] + helper(m - A[len - 1], A, V, len - 1), helper(m, A, V, len - 1));
    }
};

int main() {
    auto *so = new SolutionRecursion();
    vector<int> A{2, 3, 5, 7};
    vector<int> V{1, 5, 2, 4};
    int m = 10;
    int res = so->backPackII(m, A, V);
    cout << res << endl;
    delete so;
    return 0;
}
