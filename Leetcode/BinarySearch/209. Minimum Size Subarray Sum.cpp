class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int) nums.size();
        int pref[n + 1];
        pref[0] = 0;
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + nums[i];
        if (pref[n] < target) return 0;
        auto possible = [&] (int length) {
            for (int r = length; r <= n; ++r) {
                if (pref[r] - pref[r - length] >= target) return true;
            }
            return false;
        };
        int l = 1, r = n;
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (possible(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};