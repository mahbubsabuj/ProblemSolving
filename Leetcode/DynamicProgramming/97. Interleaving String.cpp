class Solution {
public:
    int dp[110][110][210];
    int f (int i, int j, int k, string &s1, string &s2, string &s3) {
        if (i == (int) s1.size() && j == (int) s2.size() && k == (int) s3.size()) return 1;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int res1 = 0, res2 = 0;
        if (i < (int) s1.size() && s3[k] == s1[i]) {
            res1 = f(i + 1, j, k + 1, s1, s2, s3);
        }
        if (j < (int) s2.size() && s3[k] == s2[j]) {
            res2 = f(i, j + 1, k + 1, s1, s2, s3);
        }
        return dp[i][j][k] = max(res1, res2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if ((int) s1.size() + (int) s2.size() != (int) s3.size()) return false;
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                for (int k = 0; k <= 200; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return f(0, 0, 0, s1, s2, s3);
    }
};