/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length != t.length) return false;
    const hash = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        hash[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
        hash[t.charCodeAt(i) - 'a'.charCodeAt(0)]--;
    }
    for (let i = 0; i < 26; i++) {
        if (hash[i] !== 0) return false;
    }
    return true;
};