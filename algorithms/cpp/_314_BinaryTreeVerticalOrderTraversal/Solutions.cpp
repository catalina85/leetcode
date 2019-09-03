#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<pair<TreeNode *, int>> q;
        map<int, vector<int>> m;
        map<int, vector<int>>::iterator itr;
        q.push({root, 0});
        while (!q.empty()) {
            vector<int> level;
            pair<TreeNode *, int> curr = q.front();
            m[curr.second].push_back(curr.first->val);
            q.pop();
            if (curr.first->left)
                q.push({curr.first->left, curr.second - 1});
            if (curr.first->right)
                q.push({curr.first->right, curr.second + 1});
        }
        for (itr = m.begin(); itr != m.end(); itr++) {
            res.push_back(itr->second);
        }
        return res;
    }
};

int main() {
    //       1
    //     /  \
    //    2   3
    //  /  \
    // 4   5
    auto *so = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    vector<vector<int>> res = so->verticalOrder(root);
    for (auto &level:res) {
        for (int &ele:level)
            cout << ele << " ";
        cout << endl;
    }
    delete so;
    return 0;
}