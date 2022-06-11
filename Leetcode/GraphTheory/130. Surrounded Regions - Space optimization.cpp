class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = (int) board.size();
        int m = (int) board[0].size();
        //vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto bfs = [&] (int x, int y) {
            if (board[x][y] != 'O') return;
            board[x][y] = '$'; //make (i, j) visited
            queue<pair<int, int>> q;
            q.push(make_pair(x, y));
            while (!q.empty()) {
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for (pair<int, int> dir : dirs) {
                    int dx = dir.first + x;
                    int dy = dir.second + y;
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && board[dx][dy] == 'O') {
                        q.push(make_pair(dx, dy));
                        board[dx][dy] = '$';
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                    bfs(i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            } 
        }
    }
};