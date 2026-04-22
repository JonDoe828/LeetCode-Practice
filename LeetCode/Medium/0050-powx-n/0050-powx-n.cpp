class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n; // 防止 n = INT_MIN 时取反溢出

        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double ans = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1) { // 当前这一位是 1
                ans *= x;
            }

            x *= x;   // 底数平方
            exp /= 2; // 指数右移一位
        }

        return ans;
    }
};