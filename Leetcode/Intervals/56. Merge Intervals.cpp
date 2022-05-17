class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort (intervals.begin(), intervals.end(), [&] (vector<int> & a, vector<int> & b) {
            return a[0] < b[0];
        });
        vector<int> current = intervals[0];
        int n = (int) intervals.size();
        vector<vector<int>> res;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= current[0] && intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                res.push_back(current);
                current = intervals[i];
            }
        }
        res.push_back(current);
        return res;
    }
};