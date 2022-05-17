class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        for (char c : tasks) {
            ++cnt[c - 'A'];
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) continue;
            pq.push(cnt[i]);
        }
        queue<pair<int, int>> q; //this will maintain popped count and time(when it will can be added again)
        int res = 0;
        for (int time = 1; ; ++time) {
            if (pq.empty() && q.empty()) {
                res = time - 1;
                break;
            }
            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
            if (pq.empty()) continue;
            int top = pq.top();
            pq.pop();
            if (top - 1 > 0) {
                q.push(make_pair(top - 1, time + n + 1)); //time + n + 1 is when it will be added again
            }
        }
        return res;
    }
};