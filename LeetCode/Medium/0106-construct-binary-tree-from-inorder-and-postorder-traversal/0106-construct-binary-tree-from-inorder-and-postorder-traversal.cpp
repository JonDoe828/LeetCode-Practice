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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
            return NULL;

        // Last element of postorder is the root node
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        // Leaf node
        if (postorder.size() == 1)
            return root;

        // Locate delimiter
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size();
             delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue)
                break;
        }

        // Slice inorder into left and right
        vector<int> leftInorder(inorder.begin(),
                                inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + delimiterIndex + 1,
                                 inorder.end());

        // Omit last element from postorder
        postorder.resize(postorder.size() - 1);

        // Slice postorder
        vector<int> leftPostorder(postorder.begin(),
                                  postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(),
                                   postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
};