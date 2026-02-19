class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1]; // h相同，k小的在前
        return a[0] > b[0];     // h降序
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for (auto& p : people) {
            ans.insert(ans.begin() + p[1], p); // 插到k位置
        }
        return ans;
    }
};