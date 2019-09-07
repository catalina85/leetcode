#include <iostream>
#include <vector>
#include <queue>
#include <myVector.h>
#include <myTreeNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
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
            res.insert(res.begin(), level);
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
    vector<vector<int>> res = so->levelOrderBottom(root);
    print_2d_vector(res);
    delete so;
    return 0;
}