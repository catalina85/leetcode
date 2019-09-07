#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        return helper(nums, 0, nums.size() - 1);

    }

    int helper(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];

        int mid = (end + start) / 2;

        int left = helper(nums, start, mid);
        int right = helper(nums, mid + 1, end);
        int crossingSum = maxCrossingSum(nums, start, end, mid);


        return max(left, right, crossingSum);


    }

    int maxCrossingSum(vector<int> &nums, int start, int end, int mid) {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = mid; i >= start; i--) {
            sum = sum + nums[i];
            if (sum > left_sum)
                left_sum = sum;
        }
        sum = 0;
        int right_sum = INT_MIN;
        for (int i = mid + 1; i <= end; i++) {
            sum = sum + nums[i];
            if (sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }


    int max(int a, int b, int c) {
        return (a > b ? a : b) > c ? (a > b ? a : b) : c;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = so->maxSubArray(nums);
    print(res);
    delete so;
    return 0;
}
