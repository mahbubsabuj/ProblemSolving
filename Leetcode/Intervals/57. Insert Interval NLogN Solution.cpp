class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort (intervals.begin(), intervals.end(), [&] (vector<int> a, vector<int> b) {
            if (a[0] < b[0]) return true;
            return false;
        });
        vector<vector<int>> res;
        vector<int> current = intervals[0];
        for (int i = 1; i < (int) intervals.size(); ++i) {
            if (intervals[i][0] >= current[0] && intervals[i][0] <= current[1]) {
                current[1] = max(intervals[i][1], current[1]);
            } else {
                res.push_back(current);
                current = intervals[i];
            }
        }
        res.push_back(current);
        return res;
    }
};