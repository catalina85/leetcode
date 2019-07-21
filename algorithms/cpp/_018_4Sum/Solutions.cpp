#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len - 3; i++) {
            if (i && nums[i - 1] == nums[i]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j != i + 1 && nums[j - 1] == nums[j]) continue;
                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left - 1] == nums[left])left++;
                        while (left < right && nums[right + 1] == nums[right]) right--;
                    } else if (sum > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{1, 0, -1, 0, -2, 2};
//    vector<int> nums{};
    int target = 0;

    auto *so = new Solution();
    vector<vector<int>> res = so->fourSum(nums, target);
    for (vector<int> &vect:res) {
        for (int &x:vect)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
