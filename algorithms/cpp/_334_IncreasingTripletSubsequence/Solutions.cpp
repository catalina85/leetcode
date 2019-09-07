#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3)
            return false;
        vector<int> records(2, INT_MAX);
        for (int &num:nums) {
            if (num <= records[0]) {
                records[0] = num;
            } else if (num <= records[1]) {
                records[1] = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2, 3, 3};
    bool res = so->increasingTriplet(nums);
    print(res);
    delete so;
    return 0;
}