class Solution {
public:
    string reverseWords(string s) {
        // 1. 去掉多余空格（原地压缩）
        removeExtraSpaces(s);

        // 2. 整体反转
        reverse(s.begin(), s.end());

        // 3. 再把每个单词反转回来
        int n = s.size();
        int start = 0;
        for (int i = 0; i <= n; ++i) {
            // 到了一个单词的末尾（遇到空格或到字符串末尾）
            if (i == n || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1; // 下一个单词的开头
            }
        }
        return s;
    }

private:
    void removeExtraSpaces(string& s) {
        int n = s.size();
        int slow = 0, fast = 0;

        while (fast < n) {
            if (s[fast] != ' ') {
                // 拷贝非空字符
                s[slow++] = s[fast++];
            } else {
                // 当前是空格，只在前面已经有字符且前一位不是空格时保留一个
                if (slow != 0 && s[slow - 1] != ' ') {
                    s[slow++] = ' ';
                }
                fast++;
            }
        }

        // 如果最后是空格，slow 会停在它后面，这一步相当于把尾部多余部分删掉
        if (slow > 0 && s[slow - 1] == ' ')
            slow--;

        s.resize(slow);
    }
};