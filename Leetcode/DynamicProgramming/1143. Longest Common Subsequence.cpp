class Solution {
public:
    //recursive
    /*
    static const int maxN = 1010; 
    int dp[maxN][maxN];
    int f (int i, int j, string &s, string &t) {
        if (i == (int) s.size() || j == (int) t.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = 1 + f(i + 1, j + 1, s, t);
        } else {
            return dp[i][j] = max(f(i + 1, j, s, t), f(i, j + 1, s, t));
        }
    }
    */
    int longestCommonSubsequence(string s, string t) {
        /*
        for (int i = 0; i < maxN; ++i) {
            for (int j = 0; j < maxN; ++j) {
                dp[i][j] = -1;
            }
        }
        return f(0, 0, s, t);
        */
        //iterative
        int n = (int) s.size();
        int m = (int) t.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
            }
        }
        return dp[n][m];
    }
};