class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int lo = 1, n = nums.size() - 1; // 值域是 1 到 n
        while (lo < n) {
            int mid = lo + (n - lo) / 2;

            int cnt = 0;
            for (int x : nums) {
                if (x <= mid)
                    cnt++;
            }

            if (cnt > mid) {
                n = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};