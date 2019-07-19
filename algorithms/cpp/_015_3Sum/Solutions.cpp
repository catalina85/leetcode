#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j - 1] == nums[j]) j++;
                    while (j < k && nums[k + 1] == nums[k]) k--;
                } else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
            }
        }
        return res;
    }
};

int main() {
//    Given array nums = [-1, 0, 1, 2, -1, -4],
//    A solution set is:
//    [
//    [-1, 0, 1],
//    [-1, -1, 2]
//    ]
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    auto *so = new Solution();
    vector<vector<int>> res = so->threeSum(nums);
    for (vector<int> &vect:res) {
        for (int x:vect)
            cout << x << " ";
        cout << endl;
    }
}