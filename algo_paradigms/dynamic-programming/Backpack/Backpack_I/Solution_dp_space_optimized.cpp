#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        int dp[2][m + 1];
        bool bi;
        for (int i = 0; i <= m; i++) {
            if (i >= A[0]) {
                dp[0][i] = A[0];
            } else
                dp[0][i] = 0;
        }

        for (int i = 1; i < len; i++) {
            bi = i & 1;
            for (int j = 0; j <= m; j++) {
                if (j >= A[i]) {
                    dp[bi][j] = max(dp[1 - bi][j - A[i]] + A[i], dp[1 - bi][j]);
                } else {
                    dp[bi][j] = dp[1 - bi][j];
                }
            }
        }
        return dp[bi][m];
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
