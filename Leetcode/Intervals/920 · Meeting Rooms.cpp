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
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        if ((int) intervals.size() == 0) return true;
        sort (intervals.begin(), intervals.end(), [&] (Interval a, Interval b) {
            return a.start < b.start;
        });
        for (int i = 1; i < (int) intervals.size(); ++i) {
            if (intervals[i].start < intervals[i - 1].end) return false;
        }
        return true;
    }
};