class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = (int) board.size();
        int m = (int) board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool can = true;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    vector<pair<int, int>> cords;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        cords.push_back(q.front());
                        q.pop();
                        for (pair<int, int> dir : dirs) {
                            int dx = dir.first + x;
                            int dy = dir.second + y;
                            if (dx >= 0 && dx < n && dy >= 0 && dy < m) {
                                if (!visited[dx][dy] && board[dx][dy] == 'O') {
                                    q.push(make_pair(dx, dy));
                                    visited[dx][dy] = true;
                                }
                            } else {
                                can = false;
                            }
                        }
                    }
                    if (can) {
                        for (pair<int, int> p : cords) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};