class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // 1. 移除窗口外的下标
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // 2. 维护单调递减
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};