class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0, sum = 0;
        int max_element = INT_MIN;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            max_element = max(max_element, nums[i]);
            sum += nums[i];
            res = max(sum, res);
            sum = max(sum, 0);
        }
        if (max_element < 0) {
            return max_element;
        }
        return res;
    }
};
