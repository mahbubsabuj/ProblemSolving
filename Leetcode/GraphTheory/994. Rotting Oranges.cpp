class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<pair<int, int>, int>> q; // cell & move;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(make_pair(i, j), 0));
                    visited[i][j] = true;
                }
            }
        }
        int res = 0;
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            res = max(res, cost);
            for (pair<int, int> dir : dirs) {
                int dx = x + dir.first;
                int dy = y + dir.second;
                if (dx >= 0 && dy >= 0 && dx < n && dy < m && grid[dx][dy] == 1 && !visited[dx][dy]) {
                    q.push(make_pair(make_pair(dx, dy), cost + 1));
                    visited[dx][dy] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return res;
    }
};


//2 1 1
//0 1 1 
//1 0 1    