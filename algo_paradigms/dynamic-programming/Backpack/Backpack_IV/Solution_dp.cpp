#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int backPackIV(vector<int> &nums, int target) {
        // Write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (auto a : nums) {
            for (int i = a; i <= target; ++i) {
                dp[i] += dp[i - a];
            }
        }
        return dp.back();
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 6, 7};
    int target = 7;
    int res = so->backPackIV(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}

