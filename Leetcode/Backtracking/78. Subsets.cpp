class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    void f(vector<int> &nums, int idx = 0) {
        if (idx == (int) nums.size()) {
            res.push_back(v);
            return;
        }
        f(nums, idx + 1);
        v.push_back(nums[idx]);
        f(nums, idx + 1);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums);
        return res;
    }
};