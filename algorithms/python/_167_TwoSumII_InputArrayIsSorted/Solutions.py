class Solution:
    def twoSum(self, numbers, target):
        left, right = 0, len(numbers) - 1
        while (left < right):
            if numbers[left] + numbers[right] == target:
                return [left + 1, right + 1]
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                left += 1
        return [-1, -1]


if __name__ == "__main__":
    numbers = [2, 7, 11, 15]
    target = 9

    so = Solution()
    res = so.twoSum(numbers, target)
    print(res)
