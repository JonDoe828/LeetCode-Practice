// class Solution {
// public:
//     int numSquares(int n) {
//         std::vector<int> dp(n + 1, n); 
//         dp[0] = 0;
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j * j <= i; ++j) {
//                 dp[i] = std::min(dp[i], dp[i - j * j] + 1);
//             }
//         }
//         return dp[n];
//     }
// };



class Solution {
    static bool isSquare(int x) {
        int r = (int)std::sqrt(x);
        return r * r == x;
    }
public:
    int numSquares(int n) {
        if (isSquare(n)) return 1;
        // 去掉 4 的因子
        int m = n;
        while ((m & 3) == 0) m >>= 2;
        if (m % 8 == 7) return 4;
        // 是否为两个平方和
        for (int a = 1; a * a <= n; ++a) {
            if (isSquare(n - a * a)) return 2;
        }
        return 3;
    }
};