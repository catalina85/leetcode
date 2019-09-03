# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while (curr is not None or len(stack) > 0):
            while (curr is not None):
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res


if __name__ == "__main__":
    #       1
    #     /  \
    #    2   3
    #  /  \
    # 4   5
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right = TreeNode(3)

    so = Solution()
    res = so.inorderTraversal(root)
    print(res)
