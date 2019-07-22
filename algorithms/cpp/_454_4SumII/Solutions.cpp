#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int res = 0;
        unordered_map<int, int> unorderedMap;
        for (const auto &a : A) {
            for (const auto &b:B) {
                ++unorderedMap[a + b];
            }
        }
        for (const auto &c:C) {
            for (const auto &d:D) {
                res += unorderedMap[-c - d];
            }
        }
        return res;
    }
};

int main() {
    vector<int> A{1, 2};
    vector<int> B{-2, -1};
    vector<int> C{-1, 2};
    vector<int> D{0, 2};

    auto *so = new Solution();
    int res = so->fourSumCount(A, B, C, D);
    cout << res << endl;
    delete so;

    return 0;
}
