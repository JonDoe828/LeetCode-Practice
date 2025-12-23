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
    // vector<int> res;

    // void dfs(TreeNode* root) {
    //     if (!root)
    //         return;

    //     dfs(root->left);
    //     res.push_back(root->val);
    //     dfs(root->right);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     dfs(root);
    //     return res;
    // }



    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        if (cur) {
            st.push(cur);
            cur = cur->left;        // 一直向左访问
        } else {
            cur = st.top(); st.pop();
            res.push_back(cur->val); // 中
            cur = cur->right;        // 转向右子树
        }
    }
    return res;
}
};

