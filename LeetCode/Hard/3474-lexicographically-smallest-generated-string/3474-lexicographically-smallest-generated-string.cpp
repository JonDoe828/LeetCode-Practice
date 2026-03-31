class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = n + m - 1;

        string ans(len, '?');
        vector<bool> fixed(len, false);

        // 1. 先处理 T
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;
                    if (ans[pos] == '?') {
                        ans[pos] = str2[j];
                        fixed[pos] = true;
                    } else if (ans[pos] != str2[j]) {
                        return "";
                    } else {
                        fixed[pos] = true;
                    }
                }
            }
        }

        // 2. 其余位置先填 a
        for (int i = 0; i < len; i++) {
            if (ans[i] == '?') ans[i] = 'a';
        }

        // 3. 处理 F
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (ans[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }

                if (!equal) continue;

                // 当前窗口刚好等于 str2，必须改一个位置
                bool changed = false;
                for (int j = m - 1; j >= 0; j--) {
                    int pos = i + j;
                    if (!fixed[pos]) {
                        // 改成最小的不一样字符
                        ans[pos] = (str2[j] == 'a') ? 'b' : 'a';
                        changed = true;
                        break;
                    }
                }

                if (!changed) return "";
            }
        }

        return ans;
    }
};