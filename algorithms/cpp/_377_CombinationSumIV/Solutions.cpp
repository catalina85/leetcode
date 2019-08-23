#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        unsigned long f[target + 1];
        memset(f, 0, sizeof(f));

        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++)
                if (i - nums[j] >= 0) {
                    f[i] += f[i - nums[j]];
                }
        }
        return f[target];
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{3, 33, 333};
    int target = 10000;
    int res = so->combinationSum4(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}