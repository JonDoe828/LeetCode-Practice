class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            vector<int> cnt(26, 0);
            for (char c : s) {
                cnt[c - 'a']++;
            }

            string key;
            for (int x : cnt) {
                key += to_string(x) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};