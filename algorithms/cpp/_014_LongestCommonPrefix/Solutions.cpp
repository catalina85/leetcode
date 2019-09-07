#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        string res;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].length() < i || strs[0][i] != strs[j][i])
                    return res;
            }
            res.append(1, strs[0][i]);
        }
        return res;
    }
};

int main() {
    vector<string> strs{"flower", "flow", "flight"};
    auto *so = new Solution();
    string res = so->longestCommonPrefix(strs);
    print(res);
    delete so;
    return 0;
}
