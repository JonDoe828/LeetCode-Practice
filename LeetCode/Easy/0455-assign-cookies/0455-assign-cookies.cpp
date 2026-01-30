class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = (int)s.size() - 1; // 饼干指针（从大到小）
        int ans = 0;

        for (int i = (int)g.size() - 1; i >= 0; --i) { // 孩子胃口（从大到小）
            if (j >= 0 && s[j] >= g[i]) {
                ++ans;
                --j; // 用掉这块最大的饼干
            }
            // 不满足也没关系：这个大胃口孩子只能放弃，继续看下一个胃口更小的
        }
        return ans;
    }
};