// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         stack<int> st;
//         vector<int> res(n, 0);
//         st.push(0);

//         for (int i = 1; i < n; i++) {
//             if (temperatures[i] < temperatures[st.top()]) {
//                 st.push(i);
//             } else if (temperatures[i] == temperatures[st.top()]) {
//                 st.push(i);
//             } else {
//                 while (!st.empty() &&
//                        temperatures[i] > temperatures[st.top()]) {
//                     res[st.top()] = i - st.top();
//                     st.pop();
//                 }
//                 st.push(i);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st; // 递增栈
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) { // 注意栈不能为空
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};