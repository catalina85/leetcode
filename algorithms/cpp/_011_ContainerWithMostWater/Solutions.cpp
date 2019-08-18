#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int res = 0;

        while (start < end) {
            res = max(res, min(height[start], height[end]) * (end - start));
            if (height[start] > height[end])
                end--;
            else
                start++;
        }
        return res;
    }
};

int main() {
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    auto *so = new Solution();
    int res = so->maxArea(height);
    cout << res << endl;
    delete so;
    return 0;
}
