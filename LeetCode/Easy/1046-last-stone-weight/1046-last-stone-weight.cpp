class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> que;
        int n = stones.size();

        for (int i = 0; i < n; i++) {
            que.push(stones[i]);
        }

        while (que.size() > 1) {
            int y = que.top();
            que.pop();

            int x = que.top();
            que.pop();

            if (y != x) {
                int left = y - x;
                que.push(left);
            }
        }

        return que.empty() ? 0 : que.top();
    }
};