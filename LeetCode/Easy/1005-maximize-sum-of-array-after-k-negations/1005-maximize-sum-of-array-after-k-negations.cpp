class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) > abs(b); });

        for (int& x : nums) {
            if (x < 0 && k > 0) {
                x = -x;
                --k;
            }
        }

        // 只需要看奇偶：k 为奇数就翻绝对值最小的那个（排序后在末尾）
        if (k % 2 == 1)
            nums.back() = -nums.back();

        long long sum = 0;
        for (int x : nums)
            sum += x;
        return (int)sum;
    }
};