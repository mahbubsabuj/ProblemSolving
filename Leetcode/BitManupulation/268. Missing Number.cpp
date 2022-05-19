class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int) nums.size();
        int res = nums[0] ^ n;
        for (int i = 1; i < n; ++i) {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
