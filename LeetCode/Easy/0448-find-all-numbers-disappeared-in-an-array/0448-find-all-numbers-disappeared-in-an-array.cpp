class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int m = nums.size();
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int x = nums[i];
            if (x < 0)
                x = -x;

            int idx = x - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < m; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};