class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;

        // 小顶堆：按频次从小到大
        using P = pair<int, int>; // (freq, val)
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto& kv : cnt) {
            pq.push({kv.second, kv.first});
            if ((int)pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res; // 顺序任意
    }
};