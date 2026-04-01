class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // 按位置排序，处理真实空间顺序
        sort(idx.begin(), idx.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });

        stack<int> st; // 存放还活着的、向右走的机器人下标

        for (int id : idx) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
                // 当前是 L，尝试和左边最近的 R 连续碰撞
                while (!st.empty() && healths[id] > 0) {
                    int topId = st.top();

                    if (healths[topId] < healths[id]) {
                        // 栈顶 R 死，当前 L 掉 1 点血继续打
                        st.pop();
                        healths[id]--;
                        healths[topId] = 0;
                    } else if (healths[topId] == healths[id]) {
                        // 同归于尽
                        st.pop();
                        healths[topId] = 0;
                        healths[id] = 0;
                        break;
                    } else {
                        // 当前 L 死，栈顶 R 掉 1 点血
                        healths[topId]--;
                        healths[id] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for (int h : healths) {
            if (h > 0)
                ans.push_back(h);
        }
        return ans;
    }
};