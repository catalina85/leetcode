#include <iostream>
#include <vector>
#include <myutils.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;

        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            if (nums[mid] <= nums[end]) {
                if (nums[mid] < target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int res = so->search(nums, target);
    print(res);
    delete so;
    return 0;
}
