class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int) cost.size();
        int dp[n + 1];
        fill(dp, dp + n + 1, (int) 1e8);
        dp[0] = dp[1] = 0;
        for (int i = 0; i < n; ++i) {
            for (int jump = 1; jump <= 2; ++jump) {
                if (i + jump <= n) {
                    dp[i + jump] = min(dp[i + jump], dp[i] + cost[i]);
                }
            }
        }
        return dp[n];
    }
};