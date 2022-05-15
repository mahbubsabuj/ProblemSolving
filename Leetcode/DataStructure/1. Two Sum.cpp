class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> idx;
        int n = (int) nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (idx.find(target - nums[i]) != idx.end()) {
                res.push_back(idx[target - nums[i]]);
                res.push_back(i);
                break;
            }
            idx[nums[i]] = i;
        }
        return res;
    }
};