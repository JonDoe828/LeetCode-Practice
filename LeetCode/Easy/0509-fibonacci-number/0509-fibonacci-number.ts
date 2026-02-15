function fib(n: number): number {
    if (n <= 1) return n
    let a: number = 0
    let b: number = 1
    for (let i = 2; i <= n; i++) {
        const s: number = a + b
        a = b
        b = s
    }
    return b
};