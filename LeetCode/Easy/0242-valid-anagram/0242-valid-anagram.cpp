class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> count(26, 0); // 用数组代替哈希表，只考虑小写字母 a-z

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++; // s 中的字符加一
            count[t[i] - 'a']--; // t 中的字符减一
        }

        for (int c : count) {
            if (c != 0)
                return false; // 有字符数量不同
        }

        return true;
    }
};