class Solution {
public:
    int f (vector<int>& nums, map<pair<int, int>, int> &dp, int target, int idx = 0) {
        if (idx == (int) nums.size() && target == 0) return 1;
        if (idx == (int) nums.size()) return 0;
        if (dp.find(make_pair(idx, target)) != dp.end()) return dp[make_pair(idx, target)];
        return dp[make_pair(idx, target)] = f(nums, dp, target - nums[idx], idx + 1) + f(nums, dp, target + nums[idx], idx + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return f(nums, dp, target);
    }
};