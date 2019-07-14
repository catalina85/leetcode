class Solution:
    def twoSum(self, nums, target):
        map = {}
        for i in range(len(nums)):
            if target - nums[i] in map:
                return map.get(target - nums[i]), i
            map[nums[i]] = i

        raise SyntaxError('No two sum solution')


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26

    so = Solution()
    res = so.twoSum(nums, target)
    print(res)