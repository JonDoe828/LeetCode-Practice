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
    vector<int> piles;              
    for (int x : nums) {
        int l = 0, r = piles.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (piles[m] < x)
                l = m + 1;
            else
                r = m;
        }
        if (l == piles.size())      // 说明没找到 >= x 的堆顶，要新开一堆
            piles.push_back(x);
        else                        // 找到了第一个 >= x 的堆顶，替换之
            piles[l] = x;
    }
    return piles.size();
    }
};