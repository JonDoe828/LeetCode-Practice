class Trie {
public:
    struct TrieNode {
        bool isEnd = false;
        TrieNode* children[26] = {};
    };

    Trie() : root(new TrieNode()) {}

    void insert(string word) {
        TrieNode* node = root;
        for (auto& c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (auto& c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto& c : prefix) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return false;
            }
            node = node->children[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */