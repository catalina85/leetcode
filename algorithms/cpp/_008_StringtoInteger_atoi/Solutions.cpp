#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string &str) {
        int i = 0, length = str.length(), sigh = 1;
        long long ret = 0;

        while (i < length && str[i] == ' ') i++;
        if (i == length) return 0;

        if (str[i] == '+') {
            sigh = 1;
            i++;
        } else if (str[i] == '-') {
            sigh = -1;
            i++;
        }

        for (; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            ret = ret * 10 + (str[i] - '0');
            if (ret > INT_MAX) break;
        }
        ret *= sigh;
        if (ret > INT_MAX) return INT_MAX;
        if (ret < INT_MIN) return INT_MIN;
        return ret;
    }
};

int main() {
    auto *so = new Solution();
    string s1 = "4193 with words";
    string s2 = "words and 987";
    int res = so->myAtoi(s2);
    cout << res << endl;
    delete so;
    return 0;
}
