#include <iostream>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int char_set[256] = {0};
        int start = 0, cnt = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (char_set[s[i]]++ == 0) cnt++;
            while (cnt > k) {
                char_set[s[start]]--;
                if (char_set[s[start++]] == 0)cnt--;
            }
            ans = max(i - start + 1, ans);
        }
        return ans;
    }
};

int main() {
    string s = "WORLD";
    int k = 4;

    auto *so = new Solution();
    int res = so->lengthOfLongestSubstringKDistinct(s, k);
    print(res);
    return 0;
}
