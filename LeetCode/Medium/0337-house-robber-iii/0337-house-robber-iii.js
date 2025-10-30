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


var rob = function(root){
  const robM = new WeakMap(), skipM = new WeakMap();
  const st = [[root,0]];
  let ans = 0;
  while(st.length){
    const [n,f]=st.pop();
    if(!n) continue;
    if(!f){ st.push([n,1]); if(n.right) st.push([n.right,0]); if(n.left) st.push([n.left,0]); }
    else{
      const lrob= robM.get(n.left)||0,  lskip= skipM.get(n.left)||0;
      const rrob= robM.get(n.right)||0, rskip= skipM.get(n.right)||0;
      const rob  = n.val + lskip + rskip;
      const skip = Math.max(lrob,lskip) + Math.max(rrob,rskip);
      robM.set(n, rob); skipM.set(n, skip);
      ans = Math.max(rob, skip);
    }
  }
  return ans;
};