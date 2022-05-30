class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        map<vector<int>, bool> f;
        int n = (int) nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> bits;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bits.push_back(nums[i]);
                }
            }
            sort (bits.begin(), bits.end());
            if (f[bits]) continue;
            f[bits] = true;
            res.push_back(bits);
        }
        return res;
    }
};