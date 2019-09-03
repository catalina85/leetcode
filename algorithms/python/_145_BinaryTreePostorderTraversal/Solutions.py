# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def postorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        if root is None:
            return res

        while True:
            while (curr is not None):
                if (curr.right is not None):
                    stack.append(curr.right)
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            if (curr.right is not None and len(stack) > 0 and stack[-1] == curr.right):
                stack.pop()
                stack.append(curr)
                curr = curr.right
            else:
                res.append(curr.val)
                curr = None
            if (len(stack) == 0):
                break
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
    res = so.postorderTraversal(root)
    print(res)
