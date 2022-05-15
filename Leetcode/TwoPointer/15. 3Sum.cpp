class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<int>> res;
        sort (nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i - 1 >= 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (l + 1 < r && nums[l] == nums[l - 1]) ++l;
                    --r;
                    while (r - 1 > l && nums[r] == nums[r + 1]) --r;
                } else if (sum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return res;
    }
};