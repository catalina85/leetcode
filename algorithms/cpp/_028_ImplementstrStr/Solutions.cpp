#include <iostream>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;

        for (int i = 0;; i++) {
            for (int j = 0;; j++) {
                if (needle.length() == j)
                    return i;
                if (haystack.length() < i + j)
                    return -1;
                if (needle[j] != haystack[i + j])
                    break;
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    string s = "aaaaaaaaaaaac";
    string needle = "aaac";
    int index = so->strStr(s, needle);
    print(index);
    return 0;
}
