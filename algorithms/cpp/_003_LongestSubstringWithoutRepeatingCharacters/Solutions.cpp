#include <iostream>
#include <vector>
#include <set>
#include <myutils.h>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int ans = 0;
        int i = 0, j = 0;
        set<char> set;
        int length = s.length();
        while (i <= j && j < length) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j++]);
                ans = std::max(ans, j - i);
            } else
                set.erase(s[i++]);
        }
        return ans;
    }
};

int main() {
    auto *so = new Solution();
    string s = "pwwkew";
    int res = so->lengthOfLongestSubstring(s);
    print(res);
    delete so;
    return 0;
}
