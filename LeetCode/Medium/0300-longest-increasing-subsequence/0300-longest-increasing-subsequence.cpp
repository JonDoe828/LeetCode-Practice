class Solution {
public:
    // DP
    //  int lengthOfLIS(vector<int>& nums) {
    //      int n = (int)nums.size();
    //      if (n <= 1)
    //          return n;
    //      vector<int> dp(n, 1);
    //      int ans = 1;
    //      for (int i = 1; i < n; ++i) {
    //          for (int j = 0; j < i; ++j) {
    //              if (nums[i] > nums[j]) {
    //                  dp[i] = max(dp[i], dp[j] + 1); // 核心转移
    //              }
    //          }
    //          ans = max(ans, dp[i]); // 取所有 i 的最大值
    //      }
    //      return ans;
    //  }

    // Patience sorting

    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        for (int x : nums) {
            int l = 0, r = len;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] >= x)
                    r = m;
                else
                    l = m + 1;
            }
            nums[l] = x;
            if (l == len)
                len++;
        }
        return len;
    }
};