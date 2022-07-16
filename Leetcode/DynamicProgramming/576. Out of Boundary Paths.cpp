class Solution {
public:
    const int mod = 1e9 + 7;
    static const int maxN = 51;
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    int dp[maxN][maxN][maxN];
    int f (int m, int n, int maxMove, int startRow, int startColumn) {
        if (startRow == m || startRow < 0 || startColumn == n || startColumn < 0) return 1;
        if (maxMove == 0) return 0;
        if (dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        int res = 0;
        for (pair<int, int> dir : dirs) {
            res += f(m, n, maxMove - 1, startRow + dir.first, startColumn + dir.second);
            res %= mod;
        }
        return dp[startRow][startColumn][maxMove] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for (int i = 0; i <= 50; ++i) {
            for (int j = 0; j <= 50; ++j) {
                for (int k = 0; k <= 50; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return f(m, n, maxMove, startRow, startColumn);
    }
};