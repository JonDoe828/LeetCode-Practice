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

//complete binary tree method
class Solution {
public:
    int getDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }

    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);

        if (leftDepth == rightDepth) {
            // 左子树是满二叉树
            return (1 << leftDepth) + countNodes(root->right);
        } else {
            // 右子树是满二叉树
            return (1 << rightDepth) + countNodes(root->left);
        }
    }
};


// // Version 1
// class Solution {
// private:
//     int getNodesNum(TreeNode* cur) {
//         if (cur == NULL) return 0;
//         int leftNum = getNodesNum(cur->left);      // left
//         int rightNum = getNodesNum(cur->right);    // right
//         int treeNum = leftNum + rightNum + 1;      // root
//         return treeNum;
//     }
// public:
//     int countNodes(TreeNode* root) {
//         return getNodesNum(root);
//     }
// };


// // Version 2
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (root == NULL) return 0;
//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }
// };