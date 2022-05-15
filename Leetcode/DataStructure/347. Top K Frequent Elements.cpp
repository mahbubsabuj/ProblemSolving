class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
        }
        vector<pair<int, int>> res;
        for (pair<int, int> p : cnt) res.push_back(p);
        sort (res.begin(), res.end(), [&] (pair<int, int> x, pair<int, int> y) {
            return x.second > y.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; ++i) ans.push_back(res[i].first);
        return ans;
    }
};