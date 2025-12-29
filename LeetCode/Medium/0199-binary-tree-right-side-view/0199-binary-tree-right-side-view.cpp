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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL)
            que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == (size - 1))
                    result.push_back(node->val); // Add the last element of each
                                                 // level to the result
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);

                // if (i == 0)
                //     res.push_back(node->val); // 本层第一个

                // if (node->right)
                //     q.push(node->right);
                // if (node->left)
                //     q.push(node->left);
            }
        }
        return result;
    }
};