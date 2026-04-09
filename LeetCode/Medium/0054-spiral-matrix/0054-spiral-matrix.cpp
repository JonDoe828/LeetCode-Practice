class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // 1. 左 -> 右
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // 2. 上 -> 下

            for (int j = top; j <= bottom; j++) {
                res.push_back(matrix[j][right]);
            }
            right--;

            // 3. 右 -> 左
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 4. 下 -> 上
            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return res;
    }
};