#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        if (dividend == 0)
            return 0;
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = -1;
        long dividend_temp = abs(long(dividend));
        long divisor_temp = abs(long(divisor));
        long ans = divideUtil(dividend_temp, divisor_temp);

        if (INT_MAX < ans * sign)
            return INT_MAX;
        if (INT_MIN > ans * sign)
            return INT_MIN;

        return ans * sign;
    }

private:
    long divideUtil(long dividend, long divisor) {
        if (dividend < divisor)
            return 0;
        long sum = divisor;
        long multiple = 1;
        while (sum * 2 <= dividend) {
            sum *= 2;
            multiple *= 2;
        }
        return multiple + divideUtil(dividend - sum, divisor);
    }
};

int main() {
    auto *so = new Solution();
    int m = 10;
    int n = 3;
    int ans = so->divide(m, n);
    print(index);
    return 0;
}
