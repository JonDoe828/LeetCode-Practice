class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;               // 拷贝一份
            sort(key.begin(), key.end()); // 排序后作为分组标识
            mp[key].push_back(s);         // 放进去的还是原串
        }

        vector<vector<string>> res;
        for (auto& [key, group] : mp) {
            res.push_back(group);
        }
        return res;
    }
};