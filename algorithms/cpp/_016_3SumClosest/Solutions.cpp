#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = -1;
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum3 = nums[i] + nums[j] + nums[k];
                if (abs(sum3 - target) < min_diff) {
                    min_diff = abs(sum3 - target);
                    res = sum3;
                    if (min_diff == 0)
                        return sum3;
                }
                if (sum3 > target)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};


int main() {
//    vector<int> nums{-1, 2, 1, -4};
    vector<int> nums{0, 1, 2};
    int target = 1;
    auto *so = new Solution();

    cout << so->threeSumClosest(nums, target) << endl;
    delete so;
    return 0;
}
