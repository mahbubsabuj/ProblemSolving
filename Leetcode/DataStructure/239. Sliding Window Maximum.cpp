class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = (int) nums.size();
        vector<int> res;
        for (int r = 0; r < n; ++r) {
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (r + 1 < k) continue;
            if (dq.front() + k <= r) dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};