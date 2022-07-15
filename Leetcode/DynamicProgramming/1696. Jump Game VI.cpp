class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int dp[n];
        fill(dp, dp + n, 0);
        dp[0] = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(dp[0], 0));
        for (int i = 1; i < n; ++i) {
            dp[i] = nums[i];
            while (!pq.empty() && pq.top().second + k < i) {
                pq.pop();
            }
            dp[i] += pq.top().first;
            pq.push(make_pair(dp[i], i));
        }
        return dp[n - 1];
    }
};