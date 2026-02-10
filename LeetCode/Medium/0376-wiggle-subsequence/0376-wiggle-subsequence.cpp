class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1)
            return (int)nums.size();

        int preDiff = 0;
        int curDiff = 0;
        int result = 1; // 默认最右端是一个峰/谷

        for (int i = 0; i < (int)nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];

            if ((preDiff <= 0 && curDiff > 0) ||
                (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff; // 关键：只在摆动变化时更新，避免平坡误判
            }
        }
        return result;
    }
};