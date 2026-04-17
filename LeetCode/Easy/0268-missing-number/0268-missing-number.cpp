class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, sum1 = 0;
        for (int x : nums) {
            sum += x;
        }
        for (int i = 0; i <= n; i++) {
            sum1 += i;
        }
        return sum1 - sum;
    }
};