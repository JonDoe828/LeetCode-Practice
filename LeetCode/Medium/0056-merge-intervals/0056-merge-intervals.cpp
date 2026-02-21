class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        if (intervals.size() == 0)
            return result;

        // 1. 先排序（按左端点）
        sort(intervals.begin(), intervals.end());

        // 2. 初始化第一个区间
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // 如果当前区间和结果数组最后一个区间重叠
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};