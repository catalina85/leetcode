#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative = false;
        if (n < 0) {
            isNegative = true;
            n = -(n + 1);
            x = 1 / x;
        }
        double ans = powUtil(x, n);
        if (isNegative)
            return ans * x;
        return ans;
    }

private:
    double powUtil(double x, int n) {
        if (n == 0)
            return 1;
        return n % 2 == 0 ? powUtil(x * x, n / 2) : x * powUtil(x * x, n / 2);
    }
};

int main() {
    auto *so = new Solution();
    double x = 2.0;
    int n = -2;
    double res = so->myPow(x, n);
    cout << res << endl;
    delete so;
    return 0;
}