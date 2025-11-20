/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function (nums) {
    let len = 0
    for (const x of nums) {
        let l = 0, r = len;
        while (r > l) {
            let m = l + r >> 1;
            if (nums[m] >= x) {
                r = m
            } else {
                l = m + 1
            }
        }
        nums[l] = x;
        if (l == len)
            len++;
    }
    return len;
};