function minCostClimbingStairs(cost: number[]): number {
    const n:number = cost.length;
    if (n === 1) return cost[0];
    let prev2:number = cost[0]; // dp[i-2]
    let prev1:number = cost[1]; // dp[i-1]
    for (let i = 2; i < n; i++) {
        let cur:number = cost[i] + Math.min(prev1, prev2)
        prev2 = prev1
        prev1 = cur
    }
    return Math.min(prev1, prev2)
};