class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n, 0);

        if (num1 == "0" || num2 == "0")
            return "0";

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int p1 = i + j;     // 进位位置
                int p2 = i + j + 1; // 当前个位位置

                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[p2];

                res[p2] = sum % 10;
                res[p1] += sum / 10;  //比如 15 / 10 = 1
            }
        }
        string ans;
        int i = 0;

        // 跳过结果最前面的0
        while (i < res.size() && res[i] == 0) {
            i++;
        }

        // 数字转成字符
        while (i < res.size()) {
            ans.push_back(res[i] + '0');
            i++;
        }

        return ans;
    }
};