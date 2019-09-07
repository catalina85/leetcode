#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtracking(res, subset, nums, 0);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &subset, vector<int> &nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtracking(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so->subsets(nums);
    print_2d_vector(res);
    return 0;
}
