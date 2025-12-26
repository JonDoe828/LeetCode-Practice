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
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;

//         function<void(TreeNode*)> dfs = [&](TreeNode* node) {
//             if (!node)
//                 return;
//             res.push_back(node->val);
//             dfs(node->left);
//             dfs(node->right);
//         };

//         dfs(root);
//         return res;
//     }
// };

// 递归
//  class Solution {
//  public:
//      vector<int> res;

//     void dfs(TreeNode* root) {
//         if (!root) return;
//         res.push_back(root->val);
//         dfs(root->left);
//         dfs(root->right);
//     }

//     vector<int> preorderTraversal(TreeNode* root) {
//         dfs(root);
//         return res;
//     }
// };

// 迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val); // 中
            if (node->right)
                st.push(node->right); // 右先入栈
            if (node->left)
                st.push(node->left); // 左后入栈
        }
        return res;
    }
};