class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        set.reserve(nums.size());
        for (int i : nums) {

            if (!set.insert(i).second) {
                return true;
            }
            set.insert(i);
        }
        return false;
    }
};