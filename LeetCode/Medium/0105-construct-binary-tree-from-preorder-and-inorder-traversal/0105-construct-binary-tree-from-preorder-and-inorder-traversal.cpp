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
    unordered_map<int, int> mp;
    TreeNode* dfs(vector<int>& preorder, int preBegin, int preEnd,
                  vector<int>& inorder, int inBegin, int inEnd) {

        if (preBegin == preEnd)
            return nullptr;

        int rootVal = preorder[preBegin];

        TreeNode* root = new TreeNode(rootVal);

        if (preEnd - preBegin == 1)
            return root;

        int inRootIndex = mp[rootVal];
        int leftSize = inRootIndex - inBegin;

        root->left = dfs(preorder, preBegin + 1, preBegin + 1 + leftSize,
                         inorder, inBegin, inRootIndex);
        root->right = dfs(preorder, preBegin + 1 + leftSize, preEnd, inorder,
                          inRootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};