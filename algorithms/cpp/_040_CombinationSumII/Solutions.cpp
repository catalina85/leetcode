#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> templist;
        vector<int> visit(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtracking(res, templist, visit, nums, target, 0);
        return res;
    }

private:
    void
    backtracking(vector<vector<int>> &res, vector<int> &templist, vector<int> &visit, vector<int> &nums, int target,
                 int start) {
        if (target < 0)
            return;
        else if (target == 0)
            res.push_back(templist);
        else {
            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i - 1] == nums[i]) {
                    continue;
                }
                visit[i] = 1;
                templist.push_back(nums[i]);
                backtracking(res, templist, visit, nums, target - nums[i], i + 1);
                visit[i] = 0;
                templist.pop_back();
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = so->combinationSum2(nums, target);
    print_2d_vector(res);
    delete so;
    return 0;
}
