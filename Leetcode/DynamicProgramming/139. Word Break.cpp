class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = (int) s.size();
        bool dp[n + 1];
        fill(dp, dp + n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (string word : wordDict) {
                int m = (int) word.size();
                if (i - m >= 0 && dp[i - m] && s.substr(i - m, m) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}