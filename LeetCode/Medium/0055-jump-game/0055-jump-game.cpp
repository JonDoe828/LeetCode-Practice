class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1)
            return true;

        int cover = 0;                     // 最远可达下标
        for (int i = 0; i <= cover; ++i) { // 关键：i 必须在可达范围内
            cover = max(cover, i + nums[i]);
            if (cover >= n - 1)
                return true;
        }
        return false;
    }
};