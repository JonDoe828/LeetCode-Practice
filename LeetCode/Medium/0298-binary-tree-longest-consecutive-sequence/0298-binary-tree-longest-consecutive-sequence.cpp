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
    int ans = 0;
    void dfs(TreeNode* cur, TreeNode* parent, int length) {
        if (cur == nullptr) {
            return;
        }

        if (parent != nullptr && cur->val == parent->val + 1) {
            length++;
        } else {
            length = 1;
        }

        ans = max(ans, length);

        dfs(cur->left, cur, length);
        dfs(cur->right, cur, length);
    }

    int longestConsecutive(TreeNode* root) {
        dfs(root, nullptr, 0);
        return ans;
    }
};

// int main() {
//     /*
//             1
//              \
//               3
//              / \
//             2   4
//                  \
//                   5
//     */

//     TreeNode* root = new TreeNode(1);
//     root->right = new TreeNode(3);
//     root->right->left = new TreeNode(2);
//     root->right->right = new TreeNode(4);
//     root->right->right->right = new TreeNode(5);

//     Solution solution;
//     cout << solution.longestConsecutive(root) << endl;  // 3

//     return 0;
// }