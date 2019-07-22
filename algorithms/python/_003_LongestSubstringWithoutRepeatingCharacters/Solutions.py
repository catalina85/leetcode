class Solution:
    def lengthOfLongestSubstring(self, s):
        length, i, res = len(s), 0, 0
        map = {}
        for j in range(length):
            if s[j] in map:
                i = max(map.get(s[j]), i)

            res = max(res, j - i + 1)
            map[s[j]] = j + 1
        return res


if __name__ == "__main__":
    so = Solution()
    s = "abcabcbb"
    res = so.lengthOfLongestSubstring(s)
    print(res)
