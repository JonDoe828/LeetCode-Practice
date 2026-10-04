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
    bool isValidBST(TreeNode* root) {
        long long mn, mx;
        return dfs(root, mn, mx);
    }

    bool dfs(TreeNode* root, long long& mn, long long& mx) {
        if (root == nullptr) {
            mn = LLONG_MAX;
            mx = LLONG_MIN;
            return true;
        }

        long long lmn, lmx, rmn, rmx;
        bool leftOk = dfs(root->left, lmn, lmx);   // 先左
        bool rightOk = dfs(root->right, rmn, rmx); // 再右

        // 最后处理当前节点
        if (!leftOk || !rightOk)
            return false;
        if (lmx >= root->val)
            return false;
        if (rmn <= root->val)
            return false;

        mn = min(lmn, (long long)root->val);
        mx = max(rmx, (long long)root->val);
        return true;
    }
};