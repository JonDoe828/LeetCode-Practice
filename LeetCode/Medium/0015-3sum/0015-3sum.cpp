class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3)
            return res;

        sort(nums.begin(), nums.end());

        unordered_set<string> tripletSet;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                break;

            // 对 i 去重
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            unordered_set<int> seen; // 存放右边已经出现过的数

            for (int j = i + 1; j < n; ++j) {
                int complement = target - nums[j]; // = -nums[i] - nums[j]

                if (seen.count(complement)) {
                    // 找到一个解：nums[i], complement, nums[j]
                    vector<int> triplet = {nums[i], complement, nums[j]};
                    sort(triplet.begin(), triplet.end()); // 排序保证唯一形式

                    // 生成一个 key 用来去重
                    string key = to_string(triplet[0]) + "," +
                                 to_string(triplet[1]) + "," +
                                 to_string(triplet[2]);

                    if (!tripletSet.count(key)) {
                        tripletSet.insert(key);
                        res.push_back(triplet);
                    }
                }

                // 把当前数加入 seen，供后面的 j 使用
                seen.insert(nums[j]);
            }
        }
        return res;
    }
};