class Solution {
private:
    bool backtracking(const string& s, const unordered_set<string>& wordSet,
                      vector<bool>& memory, int startIndex) {
        if (startIndex >= s.size()) {
            return true;
        }
        // 如果memory[startIndex]不是初始值了，直接使⽤memory[startIndex]的结果
        if (!memory[startIndex])
            return memory[startIndex];
        for (int i = startIndex; i < s.size(); i++) {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (wordSet.find(word) != wordSet.end() &&
                backtracking(s, wordSet, memory, i + 1)) {
                return true;
            }
        }
        memory[startIndex] =
            false; // 记录以startIndex开始的⼦串是不可以被拆分的
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size(), 1); // -1 表示初始化状态
        return backtracking(s, wordSet, memory, 0);
    }
};