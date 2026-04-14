class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                x = i;
                break;
            }
        }

        if (x != -1) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[x] < nums[i]) {
                    swap(nums[i], nums[x]);
                    break;
                }
            }
        }

        reverse(nums.begin() + x + 1, nums.end());
    }
};