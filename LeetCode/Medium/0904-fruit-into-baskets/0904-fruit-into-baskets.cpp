class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int ans = 0;
        unordered_map<int, int> cnt;

        for (int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;

            while (cnt.size() > 2) {
                cnt[fruits[left]]--;

                if (cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }

                left++;
            }
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};