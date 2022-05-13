class Solution {
public:
    int dp[110][110];
    int f (int i, int j, int n, int m) {
        if (i == n && j == m) return 1;
        if (i > n || j > m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = f(i + 1, j, n, m) + f(i, j + 1, n, m);
    }
    int uniquePaths(int m, int n) {
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                dp[i][j] = -1;
            }
        }
        return f(1, 1, n, m);
    }
};
