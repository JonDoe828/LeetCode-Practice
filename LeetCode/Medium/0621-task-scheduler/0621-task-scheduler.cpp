class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for (char task : tasks) {
            count[task - 'A']++;
        }

        int maxFreq = 0;
        for (int c : count) {
            maxFreq = max(maxFreq, c);
        }

        int maxCount = 0;
        for (int c : count) {
            if (c == maxFreq) {
                maxCount++;
            }
        }

        int frame = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), frame);
    }
};