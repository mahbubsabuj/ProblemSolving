class Solution {
public:
    int dp[110][110];
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};
    int f (int i, int j, int n, int m, vector<vector<int>> &grid) {
        if (grid[i][j] == 1) return 0;
        if (i + 1 == n && j + 1 == m) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for (pair<int, int> dir : dirs) {
            if (i + dir.first < n && j + dir.second < m && grid[i + dir.first][j + dir.second] != 1) {
                res += f(i + dir.first, j + dir.second, n, m, grid);
            }
        }
        return dp[i][j] = res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for (int i = 0; i <= 100; ++i) {
            for (int j = 0; j <= 100; ++j) {
                dp[i][j] = -1;
            }
        }
        int n = (int) obstacleGrid.size();
        int m = (int) obstacleGrid[0].size();
        return f(0, 0, n, m, obstacleGrid);
    }
};
