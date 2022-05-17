class Solution {
public:
    bool visited[310][310];
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs (int i, int j, vector<vector<char>> &grid) {
        visited[i][j] = true;
        for (pair<int, int> dir : dirs) {
            int dx = dir.first + i;
            int dy = dir.second + j;
            if (dx >= 0 && dy >= 0 && dx < (int) grid.size() && dy < (int) grid[0].size() && grid[dx][dy] == '1' && !visited[dx][dy]) {
                dfs(dx, dy, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i <= 300; ++i) {
            for (int j = 0; j <= 300; ++j) {
                visited[i][j] = false;
            }
        }
        int res = 0;
        for (int i = 0; i < (int) grid.size(); ++i) {
            for (int j = 0; j < (int) grid[0].size(); ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ++res;
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }
};