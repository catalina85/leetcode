#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i < len + 1; i++) {
            bi = i & 1;
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[bi][j] = 0;
                else if (j < A[i - 1])
                    dp[bi][j] = dp[1 - bi][j];
                else
                    dp[bi][j] = max(V[i - 1] + dp[bi][j - A[i - 1]], dp[1 - bi][j]);
            }
        }
        return dp[bi][m];
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
