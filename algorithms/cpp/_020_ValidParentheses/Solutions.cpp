#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string &str) {
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
                s.push(str[i]);
            if (str[i] == ')') {
                if (s.empty() || s.top() != '(')
                    return false;
                else
                    s.pop();
            }
            if (str[i] == ']') {
                if (s.empty() || s.top() != '[')
                    return false;
                else
                    s.pop();
            }
            if (str[i] == '}') {
                if (s.empty() || s.top() != '{')
                    return false;
                else
                    s.pop();
            }
        }
        return s.empty();
    }
};

int main() {
    auto *so = new Solution();
    string s = "(])";
    bool res = so->isValid(s);
    cout << res << endl;
    delete so;
    return 0;
}
