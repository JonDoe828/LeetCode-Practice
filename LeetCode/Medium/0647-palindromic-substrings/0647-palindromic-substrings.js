/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function (s) {
    const n = s.length;
    let ans = 0;

    const expand = (l, r) => {
        while (l >= 0 && r < n && s[l] === s[r]) {
            ans++;        // 每扩成功一次就是一个回文子串
            l--; r++;
        }
    };

    for (let i = 0; i < n; i++) {
        expand(i, i);       // 奇数长度中心
        expand(i, i + 1);   // 偶数长度中心
    }
    return ans;
};