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
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // Process middle node
        if (cur->left == NULL && cur->right == NULL) {
            result.push_back(path);
            return;
        }
        if (cur->left)
            traversal(cur->left, path + "->", result); // Process left
        if (cur->right)
            traversal(cur->right, path + "->", result); // Process right
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == NULL)
            return result;
        traversal(root, path, result);
        return result;
    }
};