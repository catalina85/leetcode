#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        int len = A.size();
        int dp[len + 1][m + 1];
        for (int i = 0; i < len + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (j < A[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(V[i - 1] + dp[i][j - A[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[len][m];
    }

private:
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
