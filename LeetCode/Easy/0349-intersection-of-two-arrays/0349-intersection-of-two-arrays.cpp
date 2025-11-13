class Solution {
public:
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_set<int> s1(nums1.begin(), nums1.end());
    //     unordered_set<int> res;

    //     for (int i : nums2) {
    //         if (s1.count(i)) {
    //             res.insert(i);
    //         }
    //     }
    //     return vector<int>(res.begin(), res.end());
    // }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        int hash[1001] = {0};

        for (int num : nums1) {
            hash[num] = 1;
        }

        for (int num : nums2) {
            if (hash[num] == 1) {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};