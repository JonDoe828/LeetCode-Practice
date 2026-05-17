class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ans(26, 0);

        for (auto c : s) {
            ans[c - 'a']++;
        }

        for (auto c : t) {
            ans[c - 'a']--;
        }

        for (auto c : ans) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};