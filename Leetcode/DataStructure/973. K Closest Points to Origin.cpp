class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (vector<int> point : points) {
            int sq = point[0] * point[0] + point[1] * point[1];
            pq.push(make_pair(-sq, point));
        }
        vector<vector<int>> res;
        while (!pq.empty() && k) {
            --k;
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};