#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, len = nums1.size() - 1;
        while (-1 < i || -1 < j) {
            if (-1 == i) {
                nums1[len] = nums2[j];
                j--;
                len--;
                continue;
            }
            if (-1 == j) {
                nums1[len] = nums1[i];
                i--;
                len--;
                continue;
            }
            if (nums1[i] < nums2[j]) {
                nums1[len] = nums2[j];
                j--;
                len--;
            } else {
                nums1[len] = nums1[i];
                i--;
                len--;
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> A{1, 2, 3, 0, 0, 0};
    vector<int> B{2, 5, 6};
    int m = 3, n = 3;
    so->merge(A, m, B, n);
    print_1d_vector(A);
    return 0;
}
