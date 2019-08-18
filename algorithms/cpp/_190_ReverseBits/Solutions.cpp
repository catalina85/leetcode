#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = (res << 1) + (n >> i & 1);
        }
        return res;
    }
};

int main() {
    auto *so = new Solution();
    uint32_t n = 43261596;
    uint32_t res = so->reverseBits(n);
    cout << res << endl;
    return 0;
}
