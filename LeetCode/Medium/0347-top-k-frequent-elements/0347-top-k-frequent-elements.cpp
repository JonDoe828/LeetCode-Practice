class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int x : nums)
            cnt[x]++;

        // 小顶堆：按频次从小到大 / Min-heap
        using P = pair<int, int>; // (freq, val)
        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto& kv : cnt) {
            pq.push({kv.second, kv.first});
            if ((int)pq.size() > k) // 超出范围，pop掉顶部的最小值
                pq.pop();
        }

        vector<int> res; // 预分配空间, 注意与resize的区别，用resize会变成2k
        res.reserve(k);
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res; // 顺序任意
    }
};