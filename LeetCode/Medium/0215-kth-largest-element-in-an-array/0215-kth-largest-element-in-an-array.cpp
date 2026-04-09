class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[right]);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (right >= left) {
            int p = partition(nums, left, right);
            if (p == target) {
                return nums[p];
            } else if (p < target) {
                left = p + 1;
            } else {
                right = p - 1;
            }
        }
        return -1;
    }
};