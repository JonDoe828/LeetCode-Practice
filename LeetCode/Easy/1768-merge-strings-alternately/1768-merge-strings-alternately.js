/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let res = '';
    let i = 0, j = 0;
    const n1 = word1.length, n2 = word2.length;

    while (i < n1 || j < n2) {
        if (i < n1) {
            res += word1[i];
            i++;
        }
        if (j < n2) {
            res += word2[j];
            j++;
        }
    }
    return res;
};