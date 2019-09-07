#include <iostream>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        while (start + 1 < end) {
            int mid = (end + start) / 2;
            int div = x / mid;
            if (div == mid)
                return mid;
            else if (div > mid) {
                start = mid;
            } else
                end = mid;
        }
        if (x != 0 && x / end >= end)
            return end;
        return start;
    }
};

int main() {
    auto *so = new Solution();
    int x = 8;
    int ans = so->mySqrt(x);
    print(ans);
    delete so;
    return 0;
}
