/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  // 创建一个哈希表，存储：值 → 索引
  const map = new Map();

  // 遍历数组
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i]; // 当前数
    const complement = target - num; // 需要的“补数”

    // 检查 map 中是否已经有这个补数
    if (map.has(complement)) {
      // 如果找到了，直接返回补数的下标和当前下标
      return [map.get(complement), i];
    }

    // 否则，把当前值和它的索引加入 map
    map.set(num, i);
  }

  // 理论上不会执行到这一步（因为题目保证一定有解）
  return [];
};