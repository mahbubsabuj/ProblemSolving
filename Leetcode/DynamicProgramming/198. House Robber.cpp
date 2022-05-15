class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        int dp[n + 1];
        fill(dp, dp + n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) dp[i] = nums[i];
            if (i == 1) dp[i] = max(dp[i - 1], nums[i]);
            if (i > 1) {
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
        }
        return dp[n - 1];
    }
};