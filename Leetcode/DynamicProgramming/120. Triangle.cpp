class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = (int) triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, (int) 1e7));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                int x = (j - 1 < 0 ? (int) 1e7 : dp[i - 1][j - 1]);
                int y = dp[i - 1][j];
                dp[i][j] = min(x + triangle[i][j], y + triangle[i][j]);
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};