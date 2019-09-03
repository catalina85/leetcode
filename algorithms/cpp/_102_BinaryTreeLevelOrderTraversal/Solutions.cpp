#include <iostream>
#include <vector>
#include <queue>


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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int level_length = q.size();
            vector<int> level;
            for (int i = 0; i < level_length; i++) {
                TreeNode *curr = q.front();
                level.push_back(curr->val);
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            res.push_back(level);
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
    vector<vector<int>> res = so->levelOrder(root);
    for (auto &level:res) {
        for (int &ele:level)
            cout << ele << " ";
        cout << endl;
    }
    delete so;
    return 0;
}