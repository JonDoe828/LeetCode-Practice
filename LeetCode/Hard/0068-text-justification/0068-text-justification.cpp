class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0; // 当前这一行从哪个单词开始

        while (i < n) {
            int j = i;       // 当前行最后一个单词的位置
            int wordLen = 0; // 当前行所有单词总长度

            // 1. 先找这一行能放哪些单词
            while (j < n && wordLen + words[j].size() + (j - i) <= maxWidth) {
                wordLen += words[j].size();
                j++;
            }
            // 此时这一行是 [i, j-1]

            int gaps = j - i - 1;            // 空隙数
            int spaces = maxWidth - wordLen; // 这一行总共要补多少空格
            string line;

            // 2. 分情况处理这一行
            // 情况1：最后一行 or 这一行只有一个单词
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += ' ';
                    }
                }
                // 补尾部空格
                line += string(maxWidth - line.size(), ' ');
            }
            // 情况2：普通行，做左右对齐
            else {
                int avg = spaces / gaps;   // 每个空隙至少多少空格
                int extra = spaces % gaps; // 前 extra 个空隙多一个空格

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1) {
                        int cnt = avg;
                        if (extra > 0) {
                            cnt++;
                            extra--;
                        }
                        line += string(cnt, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j; // 进入下一行
        }

        return result;
    }
};