class Solution {
public:
    // bool isOneBitCharacter(vector<int>& bits) {
    //     int n = bits.size();
    //     int i = 0;

    //     while (i < n - 1) {
    //         if (bits[i] == 0)
    //             i += 1;
    //         else
    //             i += 2;
    //     }
    //     return i == n - 1;
    // }

    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int cnt = 0;
        // 从倒数第二位开始往前数连续的 1
        for (int i = n - 2; i >= 0 && bits[i] == 1; --i) {
            cnt++;
        }
        // 连续的 1 个数为偶数 → 最后一位是单独的 0（1-bit）
        // 为奇数 → 最后一位和前面某个 1 组成 2-bit
        return cnt % 2 == 0;
    }
};