#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max_profit = 0, min_val = INT_MAX;
        for (int &price:prices) {
            if (price < min_val)
                min_val = price;
            if ((price - min_val) > max_profit)
                max_profit = price - min_val;
        }
        return max_profit;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int res = so->maxProfit(prices);
    print(res);
    delete so;
    return 0;
}