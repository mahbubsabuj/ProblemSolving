class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size(); 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    int cnt = 0;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        ++cnt;
                        for (pair<int, int> dir : dirs) {
                            int dx = x + dir.first;
                            int dy = y + dir.second;
                            if (dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] == 1 && !visited[dx][dy]) {
                                q.push(make_pair(dx, dy));
                                visited[dx][dy] = true;
                            }
                        }
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};