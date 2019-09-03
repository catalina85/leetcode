#include <iostream>
#include <vector>
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
    bool isCousins(TreeNode *root, int x, int y) {
        map<int, TreeNode *> par;
        map<int, int> depth;
        if (!root)
            return false;
        helper(root, nullptr, par, depth);
        return (par[x] != par[y]) && (depth[x] == depth[y]);
    }

private:
    void helper(TreeNode *root, TreeNode *parNode, map<int, TreeNode *> &par, map<int, int> &depth) {
        if (!root)
            return;
        par[root->val] = parNode;
        depth[root->val] = (parNode == nullptr ? 0 : depth[parNode->val] + 1);
        helper(root->left, root, par, depth);
        helper(root->right, root, par, depth);
    }
};

int main() {
    //       1
    //     /  \
    //    2   3
    //  /      \
    // 4       5
    auto *so = new Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    bool res = so->isCousins(root, 4, 5);
    cout << res << endl;
    delete so;
    return 0;
}
