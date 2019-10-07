#include <iostream>
#include <vector>
#include <myTreeNode.h>
#include <myutils.h>

using namespace std;


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || preorder.size() != inorder.size())
            return nullptr;

        int length = preorder.size();
        return constructHelper(preorder, 0, length - 1, inorder, 0, length - 1);

    }

private:
    TreeNode *constructHelper(vector<int> &pre, int startPre, int endPre, vector<int> &vin, int startVin, int endVin) {
        int rootValue = pre[startPre];
        TreeNode *root = new TreeNode(rootValue);

        if (pre[startPre] == pre[endPre]) {
            if (vin[startVin] == vin[endVin] && pre[startPre] == vin[startVin])
                return root;
            else
                throw invalid_argument("invalid_argument");
        }

        int rootPos = startVin;
        while (startVin <= endVin && rootValue != vin[rootPos])
            rootPos++;
        if (rootPos == endVin && rootValue != vin[rootPos])
            throw invalid_argument("invalid_argument");

        int leftLength = rootPos - startVin;
        int leftPreEnd = startPre + leftLength;

        if (0 < leftLength)
            root->left = constructHelper(pre, startPre + 1, leftPreEnd, vin, startVin, rootPos - 1);
        if (leftLength < endPre - startPre)
            root->right = constructHelper(pre, leftPreEnd + 1, endPre, vin, rootPos + 1, endVin);

        return root;
    }
};


int main() {
    auto *so = new Solution();

    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin{4, 7, 2, 1, 5, 3, 8, 6};

    auto res = so->buildTree(pre, vin);
    preorderTraversal(res);
    cout << endl;
    inorderTraversal(res);
    delete so;
    return 0;
}


