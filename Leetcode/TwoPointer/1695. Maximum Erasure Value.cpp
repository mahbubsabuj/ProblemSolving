class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = (int) nums.size();
        int sum = 0;
        int max_sum = 0;
        int cnt[(int) 1e4 + 1] = {0};
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (cnt[nums[i]] == 0) {
                ++cnt[nums[i]];
                sum += nums[i];
            } else {
                while (cnt[nums[i]] != 0) {
                    sum -= nums[l];
                    --cnt[nums[l++]];
                }
                ++cnt[nums[i]];
                sum += nums[i];
            }
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};