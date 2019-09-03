#include <iostream>
#include <vector>

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
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int left = INT_MAX, right = INT_MAX;
        if (root->left)
            left = minDepth(root->left);
        if (root->right)
            right = minDepth(root->right);

        return min(left, right) + 1;
    }

private:
    int min(int a, int b) {
        return a > b ? b : a;
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
    int res = so->minDepth(root);
    cout << res << " ";
    delete so;
    return 0;
}