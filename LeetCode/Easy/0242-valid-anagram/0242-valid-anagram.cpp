class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> ans(26, 0);

        for (auto& c : s) {
            ans[c - 'a']++;
        }

        for (auto& c : t) {
            ans[c - 'a']--;
        }

        for (auto& c : ans) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};