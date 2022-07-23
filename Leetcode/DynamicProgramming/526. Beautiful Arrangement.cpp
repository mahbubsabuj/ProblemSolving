class Solution {
public:
    static const int maxN = (1 << 16) + 1;
    int dp[maxN][16];
    int f (int n, int mask = 0, int idx = 0) {
        if (mask == (1 << n) - 1) return 1;
        if (dp[mask][idx] != -1) return dp[mask][idx];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                if (((i + 1) % (idx + 1) == 0) || ((idx + 1) % (i + 1) == 0)) {
                    res += f(n, mask | (1 << i), idx + 1);
                }
            }
        }
        return dp[mask][idx] = res;
    }
    int countArrangement(int n) {
        memset(dp, -1, sizeof(dp));
        int res = f(n);
        return res;
    }
};
