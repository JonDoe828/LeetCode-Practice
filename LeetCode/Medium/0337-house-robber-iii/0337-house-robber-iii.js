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
// var rob = function (root) {
//     function dfs(node) {
//         if (!node) return [0, 0]; // [rob, skip]
//         const [lrob, lskip] = dfs(node.left);
//         const [rrob, rskip] = dfs(node.right);
//         const rob = node.val + lskip + rskip;
//         const skip = Math.max(lrob, lskip) + Math.max(rrob, rskip);
//         return [rob, skip];
//     }
//     const [r, s] = dfs(root);
//     return Math.max(r, s);
// };


var rob = function(root) {
  if (!root) return 0;
  const st = [[root, 0]]; // 0: first time, 1: children done
  let ans = 0;
  while (st.length) {
    const [node, flag] = st.pop();
    if (!node) continue;
    if (!flag) {
      st.push([node, 1]);
      if (node.right) st.push([node.right, 0]);
      if (node.left)  st.push([node.left, 0]);
    } else {
      const lrob = node.left ? node.left._r : 0;
      const lskip= node.left ? node.left._s : 0;
      const rrob = node.right? node.right._r: 0;
      const rskip= node.right? node.right._s: 0;
      node._r = node.val + lskip + rskip;
      node._s = Math.max(lrob, lskip) + Math.max(rrob, rskip);
      ans = Math.max(node._r, node._s);
      // 可选清理：delete node._r; delete node._s;（最后统一清也行）
    }
  }
  return ans;
};

