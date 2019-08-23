#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtracking(res, subset, nums);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &subset, vector<int> &nums) {
        if (subset.size() == nums.size())
            res.push_back(subset);

        for (int i = 0; i < nums.size(); i++) {
            if (find(subset.begin(), subset.end(), nums[i]) != subset.end())
                continue;
            subset.push_back(nums[i]);
            backtracking(res, subset, nums);
            subset.pop_back();
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so->permute(nums);
    for (auto &list: res) {
        for (auto ele: list) {
            cout << ele;
        }
        cout << endl;
    }
    delete so;
    return 0;
}
