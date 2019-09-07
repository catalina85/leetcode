#include <iostream>
#include <vector>
#include <map>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return vector<int>{m.find(target - nums[i])->second, i};
            }
            m.insert({nums[i], i});
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;

    auto *so = new Solution();
    vector<int> res = so->twoSum(nums, target);
    print_1d_vector(res);
    delete so;
    return 0;
}