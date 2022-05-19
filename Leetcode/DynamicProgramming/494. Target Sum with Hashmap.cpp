class Solution {
public:
    int f (vector<int>& nums, map<pair<int, int>, int> &dp, int target, int i) {
        if (i == (int) nums.size() && target == 0) return 1;
        if (i == (int) nums.size()) return 0;
        if (dp.find(make_pair(i, target)) != dp.end()) return dp[make_pair(i, target)];
        return dp[make_pair(i, target)] = f(nums, dp, target - nums[i], i + 1) + f(nums, dp, target + nums[i], i + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return f(nums, dp, target, 0);
    }
};
