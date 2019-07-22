#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> &vect, int k) {
        sort(begin(vect), end(vect));
        int res = -1;
        int start = 0;
        int end = vect.size() - 1;
        while (start < end) {
            if (vect[start] + vect[end] > k)
                end--;
            else {
                res = max(res, vect[start] + vect[end]);
                start++;
            }
        }
        return res;
    }
};

int main() {
//    Example 1:
//    Input: A = [34,23,1,24,75,33,54,8], K = 60
//    Output: 58
//    Explanation:
//    We can use 34 and 24 to sum 58 which is less than 60.
//
//    Example 2:
//    Input: A = [10,20,30], K = 15
//    Output: -1

    vector<int> vect{34, 23, 1, 24, 75, 33, 54, 8};
    int k = 60;
    auto *so = new Solution();
    int res = so->twoSumLessThanK(vect, k);
    cout << res << endl;
    delete so;
    return 0;
}