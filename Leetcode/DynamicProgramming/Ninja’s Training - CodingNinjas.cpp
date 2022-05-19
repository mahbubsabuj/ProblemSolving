int ninjaTraining(int n, vector<vector<int>> &points)
{
    int dp[n][3];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j] = 0;
			}
		}
		//dp[0][0] = points[0][0];
		//dp[0][1] = points[0][1];
		//dp[0][2] = points[0][2];
		for (int i = 0; i < 3; ++i) {
			dp[0][i] = points[0][i];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				int res = 0;
				if (j == 0) {
					res = max(dp[i - 1][1], dp[i - 1][2]);
				} else if (j == 1) {
					res = max(dp[i - 1][0], dp[i - 1][2]);
				} else {
					res = max(dp[i - 1][0], dp[i - 1][1]);
				}
				dp[i][j] = points[i][j] + res;
			}
		}
		return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}