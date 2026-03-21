class Solution {
public:
    vector<string> result;
    vector<string> path;

    bool isValid(const string& s, int start, int end) {
        if (start > end)
            return false;

        // 前导0
        if (s[start] == '0' && start != end)
            return false;

        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9')
                return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }

    void backtracking(string s, int startIndex) {
        if (path.size() == 4) {
            if (startIndex == s.size()) {
                result.push_back(path[0] + "." + path[1] + "." + path[2] + "." +
                                 path[3]);
            }
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (!isValid(s, startIndex, i))
                break;

            path.push_back(s.substr(startIndex, i - startIndex + 1));
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return result;
    }
};