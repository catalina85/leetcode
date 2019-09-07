#include <iostream>
#include <myutils.h>

using namespace std;

class Solution {
    /*
     * -24 / 10 = -2
     */
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            if (ret > INT32_MAX / 10 || (ret == INT32_MAX / 10 && remainder > 7)) return 0;
            if (ret < INT32_MIN / 10 || (ret == INT32_MIN / 10 && remainder < -8)) return 0;
            ret = ret * 10 + remainder;
        }
        return ret;
    }
};

int main() {
    auto *so = new Solution();
    int num = -8765;
    int res = so->reverse(num);
    print(res);
    return 0;
}
