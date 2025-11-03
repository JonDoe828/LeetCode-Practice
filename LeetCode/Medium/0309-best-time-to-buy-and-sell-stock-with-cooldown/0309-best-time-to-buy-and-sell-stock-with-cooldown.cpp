class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int hold = -prices[0], rest = 0, cool = 0;
        for (int i = 1; i < n; ++i) {
            int h = hold, r = rest, c = cool;
            hold = max(h, r - prices[i]);
            cool = h + prices[i];
            rest = max(r, c);
        }
        return max(rest, cool);
    }
};