/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    if (n <= 2) return n
    let a = 1, b = 1;
    for (let i = 2; i <= n; i++) {
        s = a + b
        a = b
        b = s
    }
    return b
};