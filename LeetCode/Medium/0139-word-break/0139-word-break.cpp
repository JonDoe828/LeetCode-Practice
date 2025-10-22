// class Solution {
// private:
//     bool backtracking(const string& s, const unordered_set<string>& wordSet,
//                       vector<bool>& memory, int startIndex) {
//         if (startIndex >= s.size()) {
//             return true;
//         }
//         //
//         如果memory[startIndex]不是初始值了，直接使⽤memory[startIndex]的结果
//         if (!memory[startIndex])
//             return memory[startIndex];
//         for (int i = startIndex; i < s.size(); i++) {
//             string word = s.substr(startIndex, i - startIndex + 1);
//             if (wordSet.find(word) != wordSet.end() &&
//                 backtracking(s, wordSet, memory, i + 1)) {
//                 return true;
//             }
//         }
//         memory[startIndex] =
//             false; // 记录以startIndex开始的⼦串是不可以被拆分的
//         return false;
//     }

// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//         vector<bool> memory(s.size(), 1); // -1 表示初始化状态
//         return backtracking(s, wordSet, memory, 0);
//     }
// };

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for (auto& w : wordDict)
            maxLen = max(maxLen, (int)w.size());

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxLen); j < i; ++j) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};