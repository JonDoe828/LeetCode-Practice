class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char c : t) {
            need[c]++;
        }

        int needCount = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                needCount++;
            }
        }

        int left = 0, right = 0;
        int valid = 0;

        int start = 0;
        int len = INT_MAX;

        while (right < s.size()) {
            char c = s[right];
            right++;

            if (need[c] > 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == needCount) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left++;

                if (need[d] > 0) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};