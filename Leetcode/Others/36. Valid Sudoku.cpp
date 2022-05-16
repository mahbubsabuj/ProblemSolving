class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int n = (int) grid.size();
        int m = (int) grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + 2 < n && j + 2 < m && i % 3 == 0 && j % 3 == 0) {
                    int cnt[10];
                    fill(cnt, cnt + 10, 0);
                    for (int x = i; x <= i + 2; ++x) {
                        for (int y = j; y <= j + 2; ++y) {
                            if (grid[x][y] >= '0' && grid[x][y] <= '9') {
                                ++cnt[grid[x][y] - '0'];
                                if (cnt[grid[x][y] - '0'] > 1) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int cnt[10];
            fill(cnt, cnt + 10, 0);
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] >= '0' && grid[i][j] <= '9') {
                    ++cnt[grid[i][j] - '0'];
                    if (cnt[grid[i][j] - '0'] > 1) return false;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            int cnt[10];
            fill(cnt, cnt + 10, 0);
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] >= '0' && grid[i][j] <= '9') {
                    ++cnt[grid[i][j] - '0'];
                    if (cnt[grid[i][j] - '0'] > 1) return false;
                }
            }
        }
        return true;
    }
};