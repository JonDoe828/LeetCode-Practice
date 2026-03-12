// class Solution {
// public:
//     vector<vector<string>> result;
//     vector<string> path;

//     bool isPalindrome(const string& s, int left, int right) {
//         while (left < right) {
//             if (s[left] != s[right])
//                 return false;
//             left++;
//             right--;
//         }
//         return true;
//     }

//     void backtracking(const string& s, int startIndex) {
//         if (startIndex == s.size()) {
//             result.push_back(path);
//             return;
//         }

//         for (int i = startIndex; i < s.size(); i++) {
//             if (!isPalindrome(s, startIndex, i)) {
//                 continue;
//             }

//             path.push_back(s.substr(startIndex, i - startIndex + 1));
//             backtracking(s, i + 1);
//             path.pop_back();
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         result.clear();
//         path.clear();
//         backtracking(s, 0);
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // 预处理回文
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;

        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                res.push_back(path);
                return;
            }

            for (int i = start; i < n; i++) {
                if (!dp[start][i]) continue;

                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1);
                path.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};