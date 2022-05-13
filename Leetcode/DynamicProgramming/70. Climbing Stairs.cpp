class Solution {
public:
    //iterative
    int climbStairs(int n) {
        int dp[n + 1];
        fill(dp, dp + n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int jump = 1; jump <= 2; ++jump) {
                if (i - jump >= 0) {
                    dp[i] += dp[i - jump];
                }
            }
        }
        return dp[n];
    }
    //recursive
    /*
    int dp[50];
    int f (int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = f(n - 1) + f(n - 2);
    }
    int climbStairs(int n) {
        fill (dp, dp + n + 1, -1);
        return f(n);
    }
    */
};
