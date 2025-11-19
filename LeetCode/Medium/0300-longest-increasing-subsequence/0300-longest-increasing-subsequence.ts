function lengthOfLIS(nums: number[]): number {
//Patience sorting
    const piles: number[] = []
    for (const x of nums) {
        let l = 0, r = piles.length
        while (l < r) {
            const m = (l + r) >> 1
            if (piles[m] < x) l = m + 1
            else r = m
        }
        piles[l] = x
    }
    return piles.length
};