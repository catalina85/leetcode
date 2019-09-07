#include <iostream>
#include <math.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int longestPalindromeSubseq(string &s) {
        int length = s.size();
        int table[length][length];
        for (int i = 0; i < length; i++) {
            table[i][i] = 1;
        }
        for (int k = 2; k <= length; k++) {
            for (int i = 0; i < length - k + 1; i++) {
                int j = i + k - 1;
                if (s[i] == s[j] && k == 2) {
                    table[i][j] = 2;
                } else if (s[i] == s[j]) {
                    table[i][j] = table[i + 1][j - 1] + 2;
                } else {
                    table[i][j] = max(table[i + 1][j], table[i][j - 1]);
                }
            }
        }
        return table[0][length - 1];
    }
};

int main() {
    string s = "bbbbbb";
    auto *so = new Solution();
    int res = so->longestPalindromeSubseq(s);
    print(res);
    delete so;
    return 0;
}