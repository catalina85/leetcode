#include <iostream>
#include <vector>
#include <myVector.h>
#include <myTreeNode.h>
#include <myutils.h>

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorderTraversalUtils(root, res);
        return res;
    }

private:
    void postorderTraversalUtils(TreeNode *root, vector<int> &res) {
        if (root == nullptr)
            return;
        postorderTraversalUtils(root->left, res);
        postorderTraversalUtils(root->right, res);
        res.push_back(root->val);
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
    vector<int> res = so->postorderTraversal(root);
    print_1d_vector(res);
    delete so;
    return 0;
}
