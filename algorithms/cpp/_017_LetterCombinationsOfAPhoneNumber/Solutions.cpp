#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    vector<string> letterCombinations(string &digits) {
        if (digits.length() == 0)
            return {};
        backtracking("", digits);
        return res;
    }

    void backtracking(string combination, string digits) {
        if (digits.length() == 0)
            res.push_back(combination);
        else {
            string letters = keyboard[digits[0] - '0'];
            for (char letter: letters)
                backtracking(combination + letter, digits.substr(1));
        }
    }
};

int main() {
    auto *so = new Solution();
    string s = "29";
    vector<string> res = so->letterCombinations(s);
    for (string &str :res)
        cout << str << endl;
    return 0;
}