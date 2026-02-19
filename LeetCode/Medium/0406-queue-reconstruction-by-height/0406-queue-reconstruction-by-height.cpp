class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1]; // h相同，k小的在前
        return a[0] > b[0];     // h降序
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (auto &p : people) {
            int pos = p[1];
            auto it = que.begin();
            while (pos--) ++it;
            que.insert(it, p);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};