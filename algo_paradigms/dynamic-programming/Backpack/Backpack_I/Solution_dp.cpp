#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[len][m + 1];
        for (int i = 0; i <= m; i++) {
            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[i][j] = max(dp[i - 1][j - A[i]] + A[i], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[len - 1][m];
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
