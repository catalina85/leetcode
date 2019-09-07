#include <iostream>
#include <unordered_map>
#include <myutils.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map.insert({'I', 1});
        map.insert({'V', 5});
        map.insert({'X', 10});
        map.insert({'L', 50});
        map.insert({'C', 100});
        map.insert({'D', 500});
        map.insert({'M', 1000});

        int ans = 0;
        ans += map.find(s[0])->second;

        for (int i = 1; i < s.length(); i++) {
            ans += map.find(s[i])->second;
            if (map.find(s[i - 1])->second < map.find(s[i])->second)
                ans -= map.find(s[i - 1])->second * 2;
        }
        return ans;
    }
};

int main() {
    auto *so = new Solution();
    string s = "MCMXCIV";
    int res = so->romanToInt(s);
    print(res);
    delete so;
    return 0;
}
