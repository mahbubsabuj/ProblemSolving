class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            res.push_back(res.back() + nums[i]);
        }
        return res;
    }
};