#include <iostream>
#include <vector>
#include <myutils.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = 0;
        if (nums.empty())
            return res;
        int start = 0;
        int end = nums.size() - 1;
        int mid = start;
        while (nums[start] >= nums[end]) {
            if (end - start == 1)
                return nums[end];
            mid = (start + end) / 2;
            if (nums[start] == nums[end] && nums[start] == nums[mid])
                return minNumInSequence(nums, start, end);
            if (nums[mid] >= nums[start])
                start = mid;
            else if (nums[mid] <= nums[end])
                end = mid;
        }
        return nums[mid];
    }
private:
    int minNumInSequence(vector<int> &nums, int start, int end) {
        int ans = nums[start];
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] < ans)
                ans = nums[i];
        }
        return ans;
    }
};


int main() {
    auto *so = new Solution();
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int res = so->findMin(nums);
    print(res);
    delete so;
    return 0;
}
