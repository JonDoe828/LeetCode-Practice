class Solution {
public:
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     vector<vector<int>> res;
    //     int n = nums.size();
    //     if (n < 4)
    //         return res;

    //     sort(nums.begin(), nums.end());

    //     for (int k = 0; k < nums.size(); k++) {
    //         // 剪枝处理
    //         if (nums[k] > target && nums[k] >= 0) {
    //             break; // 这⾥使⽤break，统⼀通过最后的return返回
    //         }
    //         // 对nums[k]去重
    //         if (k > 0 && nums[k] == nums[k - 1]) {
    //             continue;
    //         }
    //         for (int i = k + 1; i < nums.size(); i++) {
    //             // 2级剪枝处理
    //             if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
    //                 break;
    //             }
    //             // 对nums[i]去重
    //             if (i > k + 1 && nums[i] == nums[i - 1]) {
    //                 continue;
    //             }
    //             int left = i + 1;
    //             int right = nums.size() - 1;
    //             while (right > left) {
    //                 // nums[k] + nums[i] + nums[left] + nums[right] > target
    //                 // 会溢出
    //                 if ((long)nums[k] + nums[i] + nums[left] + nums[right] >
    //                     target) {
    //                     right--;
    //                     // nums[k] + nums[i] + nums[left] + nums[right] < target
    //                     // 会溢出
    //                 } else if ((long)nums[k] + nums[i] + nums[left] +
    //                                nums[right] <
    //                            target) {
    //                     left++;
    //                 } else {
    //                     res.push_back(vector<int>{nums[k], nums[i],
    //                                                  nums[left], nums[right]});
    //                     // 对nums[left]和nums[right]去重
    //                     while (right > left && nums[right] == nums[right - 1])
    //                         right--;
    //                     while (right > left && nums[left] == nums[left + 1])
    //                         left++;
    //                     // 找到答案时，双指针同时收缩
    //                     right--;
    //                     left++;
    //                 }
    //             }
    //         }
    //     }
    //     return res;
    // }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // 第一层去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // 第二层去重
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long twoSum = (long long)nums[i] + nums[j];
                long long target2 = (long long)target - twoSum;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long cur = (long long)nums[left] + nums[right];

                    if (cur == target2) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 去重：跳过相同的 left 值
                        int leftVal = nums[left];
                        while (left < right && nums[left] == leftVal) ++left;

                        // 去重：跳过相同的 right 值
                        int rightVal = nums[right];
                        while (left < right && nums[right] == rightVal) --right;
                    } else if (cur < target2) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return res;
    }
};