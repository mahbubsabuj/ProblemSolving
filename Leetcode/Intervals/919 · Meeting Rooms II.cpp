/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = (int) intervals.size();
        sort (intervals.begin(), intervals.end(), [&] (Interval a, Interval b) {
            return a.start < b.start;
        });
        priority_queue<int> pq;
        pq.push(-intervals[0].end);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (pq.top() * -1 <= intervals[i].start) {
                pq.pop();
            }
            pq.push(-intervals[i].end);
            res = max(res, (int) pq.size());
        }
        return res;
    }
};