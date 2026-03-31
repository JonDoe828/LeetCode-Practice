class Solution {
public:
    string str1, str2;
    int n, m, L;
    vector<int> pi;
    vector<vector<int>> go;
    vector<vector<int>> memo;

    vector<int> buildPi(const string& p) {
        int m = p.size();
        vector<int> pi(m, 0);
        for (int i = 1; i < m; i++) {
            int j = pi[i - 1];
            while (j > 0 && p[i] != p[j]) j = pi[j - 1];
            if (p[i] == p[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    vector<vector<int>> buildGo(const string& p, const vector<int>& pi) {
        int m = p.size();
        vector<vector<int>> go(m + 1, vector<int>(26, 0));

        for (int state = 0; state <= m; state++) {
            for (int c = 0; c < 26; c++) {
                char ch = 'a' + c;
                if (state < m && ch == p[state]) {
                    go[state][c] = state + 1;
                } else {
                    if (state == 0) go[state][c] = 0;
                    else go[state][c] = go[pi[state - 1]][c];
                }
            }
        }
        return go;
    }

    bool validTransition(int pos, int j, int c, int& nextState) {
        int raw = go[j][c];
        int start = pos - m + 1;

        if (start >= 0) {
            bool matched = (raw == m);
            if (str1[start] == 'T' && !matched) return false;
            if (str1[start] == 'F' && matched) return false;
        }

        if (raw == m) nextState = pi[m - 1];
        else nextState = raw;

        return true;
    }

    bool dfs(int pos, int j) {
        if (pos == L) return true;
        if (memo[pos][j] != -1) return memo[pos][j];

        for (int c = 0; c < 26; c++) {
            int nj;
            if (!validTransition(pos, j, c, nj)) continue;
            if (dfs(pos + 1, nj)) {
                return memo[pos][j] = 1;
            }
        }
        return memo[pos][j] = 0;
    }

    string generateString(string s1, string s2) {
        str1 = s1;
        str2 = s2;
        n = str1.size();
        m = str2.size();
        L = n + m - 1;

        pi = buildPi(str2);
        go = buildGo(str2, pi);
        memo.assign(L + 1, vector<int>(m + 1, -1));

        if (!dfs(0, 0)) return "";

        string ans;
        int pos = 0, j = 0;
        while (pos < L) {
            for (int c = 0; c < 26; c++) {
                int nj;
                if (!validTransition(pos, j, c, nj)) continue;
                if (dfs(pos + 1, nj)) {
                    ans.push_back('a' + c);
                    j = nj;
                    break;
                }
            }
            pos++;
        }
        return ans;
    }
};