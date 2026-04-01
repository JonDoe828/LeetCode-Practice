class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        int n1 = word1.size(), n2 = word2.size();

        while (i < n1 || j < n2) {
            if (i < n1) {
                res += word1[i++];
            }
            if (j < n2) {
                res.push_back(word2[j]);
                j++;
            }
        }
        return res;
    }
};