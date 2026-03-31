//hash
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> set;
//         set.reserve(nums.size());
//         for (int i : nums) {

//             if (!set.insert(i).second) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};