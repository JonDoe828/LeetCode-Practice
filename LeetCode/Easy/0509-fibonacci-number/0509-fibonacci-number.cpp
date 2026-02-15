class Solution {
public:
    int fib(int n) {
        // if (n <= 1) {
        //     return n;
        // }

        int a = 0, b = 1;
        // for (int i = 2; i <= n; i++) {
        //     int s = a + b;
        //     a = b;
        //     b = s;
        // }
        // return b;

        for (int i = 0; i < n; i++) {
            tie(a, b) = make_tuple(b, a + b);
        }
        return a;
    }
};