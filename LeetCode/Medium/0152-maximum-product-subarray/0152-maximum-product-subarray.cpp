class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int a = curMax * x;
            int b = curMin * x;

            curMax = max(x, max(a, b));
            curMin = min(x, min(a, b));

            ans = max(ans, curMax);
        }
        return ans;
    }
};