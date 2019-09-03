#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
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
    cout << ans << endl;
    delete so;
    return 0;
}
