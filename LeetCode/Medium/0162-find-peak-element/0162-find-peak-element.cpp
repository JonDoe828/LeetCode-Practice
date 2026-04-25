class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // 右边是上坡，右边一定有峰值
                left = mid + 1;
            } else {
                // 左边包含 mid，一定有峰值
                right = mid;
            }
        }
        return left;
    }
};