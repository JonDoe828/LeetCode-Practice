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
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val); // Process middle node, add to path
        if (cur->left == NULL && cur->right == NULL) { // Found a leaf node
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath); // Collect a path
            return;
        }
        if (cur->left) { // Process left
            traversal(cur->left, path, result);
            path.pop_back(); // Backtrack
        }
        if (cur->right) { // Process right
            traversal(cur->right, path, result);
            path.pop_back(); // Backtrack
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};