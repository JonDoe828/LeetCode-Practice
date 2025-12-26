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

// 递归法
//  class Solution {
//  public:
//      vector<int> res;

//     void dfs(TreeNode* root) {
//         if (!root)
//             return;

//         dfs(root->left);
//         dfs(root->right);
//         res.push_back(root->val);
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         dfs(root);
//         return res;
//     }
// };

// 迭代法

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (!root)
            return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->left)
                st.push(node->left); // 左先入栈
            if (node->right)
                st.push(node->right); // 右后入栈
        }
        reverse(res.begin(), res.end()); // 中右左 -> 左右中
        return res;
    }
};