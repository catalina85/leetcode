#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
    vector<int> vect;
public:
    bool findTarget(TreeNode *root, int k) {
        if (root == NULL)
            return false;

        inorderCollect(root);

        int start = 0;
        int end = vect.size() - 1;
        while (start < end) {
            if (vect[start] + vect[end] == k)
                return true;
            else if (vect[start] + vect[end] < k)
                start++;
            else
                end--;
        }
        return false;
    }

    TreeNode *insert(TreeNode *treeNode, int val) {
        if (treeNode == NULL) return new TreeNode(val);

        if (val < treeNode->val)
            treeNode->left = insert(treeNode->left, val);
        else
            treeNode->right = insert(treeNode->right, val);
        return treeNode;
    }

    void inorder(TreeNode *treeNode) {
        if (treeNode == NULL)
            return;
        inorder(treeNode->left);
        cout << treeNode->val << " ";
        inorder(treeNode->right);
    }

    void inorderCollect(TreeNode *treeNode) {
        if (treeNode == NULL)
            return;
        inorderCollect(treeNode->left);
        vect.push_back(treeNode->val);
        inorderCollect(treeNode->right);
    }
};


int main() {
// Input:
//     5
//    / \
//   3  6
//  / \  \
// 2   4  7
//
// Target = 9

    auto *so = new Solution();
    auto *root = new TreeNode(5);
    so->insert(root, 3);
    so->insert(root, 6);
    so->insert(root, 2);
    so->insert(root, 4);
    so->insert(root, 7);

    int target = 9;
    bool res = so->findTarget(root, 9);
    cout << res << endl;
}