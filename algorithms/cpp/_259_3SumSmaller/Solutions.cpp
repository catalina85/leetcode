#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum3 = nums[i] + nums[j] + nums[k];
                if (sum3 >= target)
                    k--;
                else {
                    res += k - j;
                    j++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{-2, 0, -1, 3};
    int target = 2;
    auto *so = new Solution();
    cout << so->threeSumSmaller(nums, target) << endl;
    return 0;
}