class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int) nums.size();
        int dp[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] == 0) return false;
            dp[i] = max(dp[i - 1] - 1, nums[i]);
        }
        return true;
    }
};