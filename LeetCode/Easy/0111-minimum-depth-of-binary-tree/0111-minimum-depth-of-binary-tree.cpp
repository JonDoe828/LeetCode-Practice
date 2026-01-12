/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        // 叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // 如果一侧为空，只能走另一侧
        if (root->left == nullptr)
            return rightDepth + 1;
        if (root->right == nullptr)
            return leftDepth + 1;

        return min(leftDepth, rightDepth) + 1;
    }
};