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

// BFS（队列)
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (!root)
//             return res;

//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             int size = q.size(); // 当前层节点数
//             vector<int> level;
//             //for (int i = 0; i < size; ++i) {
//               while (size--) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 level.push_back(node->val);

//                 if (node->left)
//                     q.push(node->left);
//                 if (node->right)
//                     q.push(node->right);
//             }
//             res.push_back(level);
//         }
//         return res;
//     }
// };

// DFS（递归 + 层号）
class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* node, int depth) {
        if (!node)
            return;
        if (depth == res.size())
            res.push_back({});
        res[depth].push_back(node->val);

        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};