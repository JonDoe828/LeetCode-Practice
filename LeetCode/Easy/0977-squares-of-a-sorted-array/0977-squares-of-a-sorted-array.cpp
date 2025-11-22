class Solution {
public:
    // vector<int> sortedSquares(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> res(n);
    //     int k = n - 1;
    //     for (int i = 0, j = k; i <= j;) {
    //         int left = nums[i] * nums[i];
    //         int right = nums[j] * nums[j];
    //         if (left > right) {
    //             res[k--] = nums[i] * nums[i];
    //             i++;
    //         } else {
    //             res[k--] = nums[j] * nums[j];
    //             j--;
    //         }
    //     }
    //     return res;
    // }


    vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);   
    int k = n - 1;

    int i = 0;
    int j = k;

    while (i <= j) {
        int left = nums[i] * nums[i];
        int right = nums[j] * nums[j];

        if (left > right) {
            res[k--] = left;
            i++;
        } else {
            res[k--] = right;
            j--;
        }
    }
    return res;
}
};