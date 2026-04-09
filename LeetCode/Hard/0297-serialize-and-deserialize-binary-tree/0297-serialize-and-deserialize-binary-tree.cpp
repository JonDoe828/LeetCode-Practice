/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "null,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    TreeNode* deserializeDFS(vector<string>& nodes, int& index) {
        if (nodes[index] == "null") {
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = deserializeDFS(nodes, index);
        root->right = deserializeDFS(nodes, index);

        return root;
    }

    vector<string> split(string data) {
        vector<string> nodes;
        string cur;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        return nodes;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data);
        int index = 0;
        return deserializeDFS(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));