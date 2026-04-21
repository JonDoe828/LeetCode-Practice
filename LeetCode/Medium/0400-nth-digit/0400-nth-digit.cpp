class Solution {
public:
    int findNthDigit(int n) {
        long long weight  = 1; // 当前这一组数字的位数：1位数、2位数、3位数...
        long long start = 1; // 当前这一组的起始数字：1、10、100...
        long long totalWeight = 9; // 当前这一组一共有多少位：9*1, 90*2, 900*3...

        // 先确定 n 落在哪一组
        while (n > totalWeight) {
            n -= totalWeight;
            weight++;
            start *= 10;
            totalWeight = 9 * start * weight;
        }

        // 找到具体是这一组里的哪个数
        long long num = start + (n - 1) / weight;

        // 找到是这个数里的第几位
        int index = (n - 1) % weight;

        string s = to_string(num);
        return s[index] - '0';
    }
};