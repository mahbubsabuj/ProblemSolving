class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int n = (int) rooms.size();
        int m = (int) rooms[0].size();
        int INF = 2147483647;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push(make_pair(make_pair(i, j), 1));
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            for (pair<int, int> dir : dirs) {
                int dx = dir.first + x;
                int dy = dir.second + y;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy] && rooms[dx][dy] == INF) {
                    visited[dx][dy] = true;
                    rooms[dx][dy] = cost;
                    q.push(make_pair(make_pair(dx, dy), cost + 1));
                }
             }
        }
    }
};