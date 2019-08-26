#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> templist;
        backtracking(res, templist, s, 0);
        return res;
    }

private:
    void backtracking(vector<vector<string>> &res, vector<string> &templist, string &s, int start) {
        if (start == s.length())
            res.push_back(templist);
        else {
            for (int i = start; i < s.length(); i++) {
                if (isPalindrome(s.substr(start, i - start + 1))) {
                    templist.push_back(s.substr(start, i - start + 1));
                    backtracking(res, templist, s, i + 1);
                    templist.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    auto *so = new Solution();
    string s = "abbaabba";
    vector<vector<string>> res = so->partition(s);
    for (auto &list: res) {
        for (auto &ele: list) {
            cout << ele << " ";
        }
        cout << endl;
    }
    delete so;
    return 0;
}