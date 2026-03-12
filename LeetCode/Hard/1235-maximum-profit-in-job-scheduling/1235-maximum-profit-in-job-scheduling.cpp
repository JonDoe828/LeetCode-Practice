class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();

        vector<array<int, 3>> jobs;
        for (int i = 0; i < n; i++)
            jobs.push_back({endTime[i], startTime[i], profit[i]});

        sort(jobs.begin(), jobs.end()); // 按 end 排序

        vector<int> dp(n);
        vector<int> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = jobs[i][0];

        for (int i = 0; i < n; i++) {
            int e = jobs[i][0];
            int s = jobs[i][1];
            int p = jobs[i][2];

            int j = upper_bound(ends.begin(), ends.begin() + i, s) -
                    ends.begin() - 1;

            int take = p;
            if (j >= 0)
                take += dp[j];

            int notake = (i > 0 ? dp[i - 1] : 0);

            dp[i] = max(take, notake);
        }

        return dp[n - 1];
    }
};