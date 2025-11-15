/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number[]} nums3
 * @param {number[]} nums4
 * @return {number}
 */
var fourSumCount = function (nums1, nums2, nums3, nums4) {
    let map = new Map();
    for (const a of nums1) {
        for (const b of nums2) {
            const sum = a + b;
            map.set(sum, (map.get(sum) || 0) + 1);
        }
    }
    let count = 0;
    for (const c of nums3) {
        for (const d of nums4) {
            const sum = c + d;
            const need = -sum;
            if (map.has(need)) {
                count += map.get(need);
            }
        }
    }
    return count;
};