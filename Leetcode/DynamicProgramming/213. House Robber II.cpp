class Solution {
public:
    int rob(vector<int>& nums) {
        //if only 1 or 2 elements on the array
        if ((int) nums.size() <= 2) {
            int res = 0;
            for (int i = 0; i < (int) nums.size(); ++i) {
                res = max(res, nums[i]);
            }
            return res;
        }
        //remove last house
        //remove first house
        int n = (int) nums.size();
        int dp[2][n + 1];
        //all elements except last or first one
        //dp[0] will consider 1....n - 1
        //dp[1] will consider 0.... n - 2
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = 0;
            }
        }
        //for 0....n - 1
        dp[0][0] = nums[0];
        dp[0][1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            dp[0][i] = max(dp[0][i - 2] + nums[i], dp[0][i - 1]);
        }
        //for 1....n - 2
        dp[1][0] = nums[1];
        dp[1][1] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; ++i) {
            dp[1][i] = max(dp[1][i - 2] + nums[i + 1], dp[1][i - 1]);
        }
        return max(dp[0][n - 2], dp[1][n - 2]);
    }
};