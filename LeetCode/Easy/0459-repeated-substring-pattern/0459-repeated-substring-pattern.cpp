class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        // t.erase(t.begin());
        // t.erase(t.end() - 1); // 掐头去尾
        string sub = t.substr(1, t.size() - 2); 
        if (sub.find(s) != std::string::npos)
            return true; // r
        return false;
    }
};