class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int) nums.size();
        int pref[n + 2];
        int suf[n + 2];
        suf[n + 1] = 1;
        pref[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] * nums[i - 1];
        }
        for (int i = n; i >= 1; --i) {
            suf[i] = suf[i + 1] * nums[i - 1];
        }
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            res.push_back(pref[i - 1] * suf[i + 1]);
        }
        return res;
    }
};