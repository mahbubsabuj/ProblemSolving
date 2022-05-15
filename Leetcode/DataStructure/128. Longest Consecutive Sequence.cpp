class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            if (s.count(nums[i])) {
                ++cnt;
                int r = nums[i];
                s.erase(r);
                while (s.count(r + 1)) {
                    s.erase(r + 1);
                    ++r;
                    ++cnt;
                }
                r = nums[i];
                while (s.count(r - 1)) {
                    s.erase(r - 1);
                    --r;
                    ++cnt;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};