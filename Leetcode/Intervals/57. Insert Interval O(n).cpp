class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool used = false;
        int n = (int) intervals.size();
        vector<vector<int>> res;
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        vector<int> current = intervals[0];
        if (newInterval[1] < current[0]) {
            res.push_back(newInterval);
            used = true;
        }
        for (int i = 1; i < n; ++i) {
            if (!used) {
                if ((newInterval[0] >= current[0] && newInterval[0] <= current[1]) || (current[0] >= newInterval[0] && current[0] <= newInterval[1])) {
                    current[0] = min(current[0], newInterval[0]);
                    current[1] = max(current[1], newInterval[1]);
                    used = true;
                    --i;
                    continue;
                }
                if (newInterval[0] > current[1] && newInterval[1] < intervals[i][0]) {
                    res.push_back(current);
                    res.push_back(newInterval);
                    current = intervals[i];
                    used = true;
                    continue;
                }
            }
            if (intervals[i][0] >= current[0] && intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } else {
                res.push_back(current);
                current = intervals[i];
            }
        }
        if (!used) {
            if ((current[0] >= newInterval[0] && current[0] <= newInterval[1]) || (newInterval[0] >= current[0] && newInterval[0] <= current[1])) {
                current[0] = min(newInterval[0], current[0]);
                current[1] = max(newInterval[1], current[1]);
                res.push_back(current);
            } else {
                if (current[0] < newInterval[0]) {
                    res.push_back(current);
                    res.push_back(newInterval);
                } else {
                    res.push_back(newInterval);
                    res.push_back(current);
                }
            }
        } else {
            res.push_back(current);
        }
        return res;
    }
};