class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != ']') {
                st.push(c);
            } else {
                string cur = "";

                while (!st.empty() && st.top() != '[') {
                    cur = st.top() + cur;
                    st.pop();
                }

                st.pop(); // 弹出 '['

                string num = "";
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);
                string repeated = "";

                while (k--) {
                    repeated += cur;
                }

                for (char ch : repeated) {
                    st.push(ch);
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};