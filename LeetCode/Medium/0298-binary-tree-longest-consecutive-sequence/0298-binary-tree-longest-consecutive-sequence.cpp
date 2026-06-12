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
    int ans = 0;
    void dfs(TreeNode* cur, TreeNode* parent, int length) {
        if (cur == nullptr) {
            return;
        }

        if (parent != nullptr && cur->val == parent->val + 1) {
            length++;
        } else {
            length = 1;
        }

        ans = max(ans, length);

        dfs(cur->left, cur, length);
        dfs(cur->right, cur, length);
    }

    int longestConsecutive(TreeNode* root) {
        dfs(root, nullptr, 0);
        return ans;
    }
};