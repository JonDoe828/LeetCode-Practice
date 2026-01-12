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

// 前序递归
//  class Solution {
//  public:
//      int depthMax  = 0;

//     void dfs(TreeNode* node, int depth) {
//         if (!node) return;

//         // 前序：先处理当前节点
//         depthMax  = max(depthMax , depth);

//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }

//     int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         dfs(root, 1);
//         return depthMax ;
//     }
// };

// 后序
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};