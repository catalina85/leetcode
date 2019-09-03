#include <iostream>
#include <vector>

using namespace std;

class Solution {

};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    delete so;
    return 0;
}
