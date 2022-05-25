class Solution {
public:
    vector<int> partitionLabels(string s) {
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        int n = (int) s.size();
        int max_idx[26];
        fill(max_idx, max_idx + 26, 0);
        for (int i = 0; i < n; ++i) {
            max_idx[s[i] - 'a'] = i;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
            bool can = true;
            int total = 0;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] > 0 && max_idx[j] > i) {
                    can = false;
                    break;
                }
                total += cnt[j];
            }
            if (can) {
                res.push_back(total);
                fill(cnt, cnt + 26, 0);
            }
        }
        return res;
    }
};