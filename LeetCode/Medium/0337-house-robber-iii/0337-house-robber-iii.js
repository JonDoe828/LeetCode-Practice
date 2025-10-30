/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var rob = function (root) {
    function dfs(node) {
        if (!node) return [0, 0]; // [rob, skip]
        const [lrob, lskip] = dfs(node.left);
        const [rrob, rskip] = dfs(node.right);
        const rob = node.val + lskip + rskip;
        const skip = Math.max(lrob, lskip) + Math.max(rrob, rskip);
        return [rob, skip];
    }
    const [r, s] = dfs(root);
    return Math.max(r, s);
};