class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> map;
        for (int a : nums1) {
            for (int b : nums2) {
                map[a + b]++;
            }
        }
        int count = 0;

        for (int c : nums3) {
            for (int d : nums4) {
                int sum = c + d;
                auto complement = map.find(-sum);
                if (complement != map.end()) {
                    count += complement->second;
                }
            }
        }
        return count;
    }
};