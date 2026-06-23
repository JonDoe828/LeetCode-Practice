class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<char> seen(n + 1, 0);
        vector<int> ans;
 

        for (int x : nums) {
            seen[x] = 1;
        }

        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};