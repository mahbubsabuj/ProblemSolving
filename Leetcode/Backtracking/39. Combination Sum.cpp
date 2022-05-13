class Solution {
public:
    vector<vector<int>> res;
    void f (vector<int>& v, int idx, int target, vector<int> ans) {
        if (target == 0) {
            res.push_back(ans);
            return;
        }
        if (idx == (int) v.size()) return;
        if (target < 0) return;
        for (int i = 0; i <= target / v[idx]; ++i) {
            if (i == 0) {
                f(v, idx + 1, target, ans);
            } else {
                ans.push_back(v[idx]);
                f(v, idx + 1, target - i * v[idx], ans);
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        f(candidates, 0, target, vector<int>{});
        return res;
    }
};