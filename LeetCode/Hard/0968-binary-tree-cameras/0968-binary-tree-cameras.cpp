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
private:
    int result = 0;

    int traversal(TreeNode* cur) {
        if (cur == NULL)
            return 2; // 空节点算已覆盖

        int left = traversal(cur->left);
        int right = traversal(cur->right);

        // 情况1：左右有未覆盖节点
        if (left == 0 || right == 0) {
            result++;
            return 1; // 当前放摄像头
        }

        // 情况2：左右有摄像头
        if (left == 1 || right == 1) {
            return 2; // 当前被覆盖
        }

        // 情况3：左右都被覆盖
        return 0; // 当前未被覆盖
    }

public:
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) {
            result++;
        }
        return result;
    }
};