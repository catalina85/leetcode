#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> templist;
        sort(nums.begin(), nums.end());
        backtracking(res, templist, nums, target, 0);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &templist, vector<int> &nums, int target, int start) {
        if (target < 0)
            return;
        else if (target == 0)
            res.push_back(templist);
        else {
            for (int i = start; i < nums.size(); i++) {
                templist.push_back(nums[i]);
                backtracking(res, templist, nums, target - nums[i], i);
                templist.pop_back();
            }
        }
    }
};


int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 4, 5, 7};
    int target = 7;
    vector<vector<int>> res = so->combinationSum(nums, target);
    print_2d_vector(res);
    delete so;
    return 0;
}
