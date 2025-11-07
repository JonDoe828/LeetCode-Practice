/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
// var longestCommonSubsequence = function (text1, text2) {
//     // Lengths of the input strings
//     const length1 = text1.length;
//     const length2 = text2.length;

//     // Create a 2D array to store the lengths of longest common subsequences
//     // for all subproblems, initialized with zero
//     const dp = Array.from({ length: length1 + 1 }, () => new Array(length2 + 1).fill(0))
//     // Build the dp array from the bottom up
//     for (let i = 1; i <= length1; ++i) {
//         for (let j = 1; j <= length2; ++j) {
//             // If characters match, take diagonal value and add 1
//             if (text1.charAt(i - 1) === text2.charAt(j - 1)) {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//             // If characters do not match, take the maximum value from 
//             // the left (dp[i][j-1]) or above (dp[i-1][j])
//             else {
//                 dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     // The bottom-right cell contains the length of the longest
//     // common subsequence of text1 and text2
//     return dp[length1][length2];
// };

var longestCommonSubsequence = function (text1, text2) {

    const n = b.length;
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= a.length; i++) {
        let prev = 0; // dp[i-1][j-1]
        for (let j = 1; j <= n; j++) {
            const temp = dp[j]; // dp[i-1][j]
            if (a[i - 1] === b[j - 1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = Math.max(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }
    return dp[n];
};