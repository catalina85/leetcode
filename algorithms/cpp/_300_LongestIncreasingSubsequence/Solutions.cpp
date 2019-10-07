#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 0);
        int max_value = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
            if (dp[i] > max_value)
                max_value = dp[i];
        }
        return max_value;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int res = so->lengthOfLIS(nums);
    print(res);
    delete so;
    return 0;
}
