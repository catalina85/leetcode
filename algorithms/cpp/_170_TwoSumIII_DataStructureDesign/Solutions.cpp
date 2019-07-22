#include <iostream>
#include <unordered_set>

using namespace std;

class TwoSum {
public:
    unordered_multiset<int> nums;

    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        nums.insert(number);
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (int num : nums) {
            int count = num == value - num ? 2 : 1;
            if (nums.count(value - num) >= count)
                return true;
        }
        return false;
    }
};

int main() {
    auto *so = new TwoSum();
    so->add(1);
    so->add(3);
    so->add(5);

    cout << so->find(4) << endl;
    cout << so->find(7) << endl;
    delete so;
}