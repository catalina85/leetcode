class Solution:
    def maxSubArray(self, nums):
        n = len(nums)
        if (n <= 0):
            return 0
        dp = [0 for _ in range(n)]
        dp[0] = nums[0]
        maxSub = nums[0]
        for i in range(1, n):
            if (dp[i - 1] > 0):
                dp[i] = nums[i] + dp[i - 1]
            else:
                dp[i] = nums[i] + 0
            maxSub = max(maxSub, dp[i])
        return maxSub


if __name__ == "__main__":
    so = Solution()
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    res = so.maxSubArray(nums)
    print(res)
