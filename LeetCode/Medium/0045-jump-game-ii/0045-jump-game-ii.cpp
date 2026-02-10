class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;      // 当前跳的边界
        int maxReach = 0; // 下一跳的最远覆盖
        int steps = 0;

        // 注意：遍历到 n-2 即可，最后一个位置不用跳
        for (int i = 0; i < n - 1; ++i) {
            maxReach = max(maxReach, i + nums[i]);

            // 到达当前层的边界，必须跳一次
            if (i == end) {
                steps++;
                end = maxReach;
            }
        }
        return steps;
    }
};