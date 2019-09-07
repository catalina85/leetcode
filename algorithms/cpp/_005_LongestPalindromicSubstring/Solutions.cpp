#include <iostream>
#include <myutils.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string &s) {
        int length = s.size();
        if (length == 0)
            return "";

        bool table[length][length];
        memset(table, 0, sizeof(table));

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < length; i++) {
            table[i][i] = true;
        }
        for (int i = 0; i < length - 1; i++) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for (int k = 3; k <= length; k++) {
            for (int i = 0; i < length - k + 1; i++) {
                int j = i + k - 1;
                if (table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = true;
                    if (k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};

int main() {
    string s = "bbbb";
    auto so = new Solution();
    string res = so->longestPalindrome(s);
    print(res);
    delete so;
}