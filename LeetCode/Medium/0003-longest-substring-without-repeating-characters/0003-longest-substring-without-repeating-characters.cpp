class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) && mp[s[i]] >= left) {
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            res = max(res, i - left + 1);
        }
        return res;
    }
};