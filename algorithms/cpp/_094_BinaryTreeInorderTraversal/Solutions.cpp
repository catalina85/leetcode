#include <iostream>
#include <vector>
#include <myTreeNode.h>
#include <myVector.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversalUtils(root, res);
        return res;
    }

private:
    void inorderTraversalUtils(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        inorderTraversalUtils(root->left, res);
        res.push_back(root->val);
        inorderTraversalUtils(root->right, res);
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
    vector<int> res = so->inorderTraversal(root);
    print_1d_vector(res);
    delete so;
    return 0;
}
