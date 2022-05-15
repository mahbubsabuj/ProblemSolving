class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = (int) nums.size();
        map<int, bool> has;
        for (int i = 0; i < n; ++i) {
            if (has[nums[i]]) {
                return true;
            }
            has[nums[i]] = true;
        }
        return false;
    }
};