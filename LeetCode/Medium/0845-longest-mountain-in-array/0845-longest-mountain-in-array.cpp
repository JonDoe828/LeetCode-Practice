class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;

        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int left = i;
                int right = i;

                while (left > 0 && arr[left - 1] < arr[left]) {
                    left--;
                }

                while (right < arr.size() - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};