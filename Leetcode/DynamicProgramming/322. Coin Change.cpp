class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = (int) 1e7;
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                }
            }
        }
        if (dp[amount] == (int) 1e7) return -1;
        return dp[amount];
    }
};