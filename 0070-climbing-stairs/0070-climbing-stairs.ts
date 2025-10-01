function climbStairs(n: number): number {
    let a = 1, b = 1;
    for (let i = 2; i <= n; i++) {
        let s = a + b
        a = b
        b = s
    }
    return b
};