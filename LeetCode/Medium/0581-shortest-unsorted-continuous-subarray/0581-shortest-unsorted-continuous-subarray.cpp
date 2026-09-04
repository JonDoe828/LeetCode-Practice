class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxVal = nums[0], right = -1, left = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] < maxVal) {
                right = i;
            } else {
                maxVal = nums[i];
            }
        }

        int minVal = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minVal) {
                left = i;
            } else {
                minVal = nums[i];
            }
        }

        if (right == -1)
            return 0;

        return right - left + 1;
    }
};