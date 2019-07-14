#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target)
                return vector<int>{left + 1, right + 1};
            else if (numbers[left] + numbers[right] > target)
                right--;
            else {
                left++;
            }
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;

    auto *so = new Solution();
    vector<int> res = so->twoSum(numbers, target);
    for (int x : res)
        cout << x << " ";
    return 0;
}
