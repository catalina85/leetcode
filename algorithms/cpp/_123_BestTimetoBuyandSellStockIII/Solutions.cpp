#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
//    vector<int> prices{7, 1, 5, 3, 6, 4};
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        vector<int> profit(prices.size());
        int buy = 0;
        buy = prices[0];
        profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            profit[i] = max(profit[i - 1], prices[i] - buy);
            buy = min(buy, prices[i]);
        }

        print_1d_vector(profit);

        int sell = prices[prices.size() - 1];
        int best = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            best = max(best, sell - prices[i] + profit[i]);
            print(best);
            sell = max(sell, prices[i]);
            print(sell);
            print();
        }
        return best;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int res = so->maxProfit(prices);
    cout << res << endl;
    delete so;
    return 0;
}
