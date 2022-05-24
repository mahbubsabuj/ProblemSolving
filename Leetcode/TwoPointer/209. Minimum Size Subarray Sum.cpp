class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int) nums.size();
        int min_length = n;
        int sum = 0;
        for (int i = 0; i < n; ++i) sum += nums[i];
        if (sum < target) return 0;
        sum = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            sum += nums[r];
            while (sum - nums[l] >= target) {
                sum -= nums[l++];
            }
            if (sum >= target) {
                min_length = min(min_length, r - l + 1);
            }
        }
        return min_length;
    }
};