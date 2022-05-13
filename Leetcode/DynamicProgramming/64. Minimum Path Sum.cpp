class Solution {
public:
    static const int maxN = 210;
    int dp[maxN][maxN];
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    int f (int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i + 1 == n && j + 1 == m) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) return dp[i][j];
        int res = (int) 1e7;
        for (pair<int, int> dir : dirs) {
            if (i + dir.first < n && j + dir.second < m) {
                res = min(grid[i][j] + f(i + dir.first, j + dir.second, n, m, grid), res);
            }
        }
        return dp[i][j] = res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < maxN; ++i) {
            for (int j = 0; j < maxN; ++j) {
                dp[i][j] = -1;
            }
        }
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        return f(0, 0, n, m, grid);
    }
};
