class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void backtracking(const string& s, int startIndex) {
        if (startIndex == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (!isPalindrome(s, startIndex, i)) {
                continue;
            }

            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        backtracking(s, 0);
        return result;
    }
};