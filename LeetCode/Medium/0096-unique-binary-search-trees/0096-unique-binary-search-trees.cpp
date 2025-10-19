// class Solution {
// public:
//     int numTrees(int n) {
//         vector<long long> G(n + 1, 0);
//         G[0] = G[1] = 1;
//         for (int m = 2; m <= n; ++m) {
//             for (int root = 1; root <= m; ++root) {
//                 G[m] += G[root - 1] * G[m - root];
//             }
//         }
//         return (int)G[n];
//     }
// };

class Solution {
public:
    int numTrees(int n) {
        long long c = 1;
        for (int k = 1; k < n; k++) {
            c = 2 * c * (2 * k + 1) / (k + 2);
        }
        return c;
    }
};