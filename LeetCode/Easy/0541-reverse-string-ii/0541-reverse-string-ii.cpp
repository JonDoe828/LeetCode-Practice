class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        // 每次处理 [i, i + 2k) 这一段
        for (int i = 0; i < n; i += 2 * k) {
            // 剩余长度 >= k：反转前 k 个
            if (i + k <= n) {
                // [i, i + k) 是左闭右开区间
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 剩余长度 < k：把剩下的全部反转
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};