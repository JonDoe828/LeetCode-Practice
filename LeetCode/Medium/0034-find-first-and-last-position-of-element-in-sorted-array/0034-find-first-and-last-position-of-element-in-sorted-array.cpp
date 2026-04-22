class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size(); // 左闭右开 [left, right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int leftPos = lowerBound(nums, target);
        int rightPos = lowerBound(nums, (long long)target + 1) - 1;
        
        if (leftPos == nums.size() || nums[leftPos] != target) {
            return {-1, -1};
        }

        return {leftPos, rightPos};
    }
};