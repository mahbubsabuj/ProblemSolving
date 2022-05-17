class Solution {
public:
    bool visited[310][310];
    vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void bfs (int i, int j, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        while(!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (pair<int, int> dir : dirs) {
                int dx = i + dir.first;
                int dy = j + dir.second;
                if (dx >= 0 && dy >= 0 && dx < (int) grid.size() && dy < (int) grid[0].size() && grid[dx][dy] == '1' && !visited[dx][dy]) {
                    q.push(make_pair(dx, dy));
                    visited[dx][dy] = true;
                }
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
                    bfs(i, j, grid);
                }
            }
        }
        return res;
    }
};