#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i & 1) == 1)
                res++;
        }
        return res;
    }
};

int main() {
    auto *so = new Solution();
    uint32_t n = 43261596;
    uint32_t res = so->hammingWeight(n);
    cout << res << endl;
    delete so;
    return 0;
}
