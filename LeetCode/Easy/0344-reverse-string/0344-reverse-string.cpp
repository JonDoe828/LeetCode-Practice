class Solution {
public:
    // void reverseString(vector<char>& s) {
    //     int i = 0;
    //     int j = s.size() - 1;
    //     while (i < j) {
    //         swap(s[i], s[j]); // 交换左右字符
    //         ++i;
    //         --j;
    //     }
    // }

    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};