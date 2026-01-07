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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL)
            que.push(root);
        vector<int> result;

        while (!que.empty()) {
            int size = que.size();
            int maxValue = INT_MIN; // Max value of each level

            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();

                maxValue = max(maxValue, cur->val);
                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            result.push_back(maxValue);
        }
        return result;
    }
};