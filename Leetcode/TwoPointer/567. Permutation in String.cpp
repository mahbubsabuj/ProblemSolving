class Solution {
public:
    bool checkInclusion(string t, string s) {
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        int n = (int) s.size();
        int m = (int) t.size();
        for (int i = 0; i < m; ++i) {
            ++cnt[t[i] - 'a'];
        }
        int pref[n + 1][26];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                pref[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ++pref[i][s[i - 1] - 'a'];
            for (int j = 0; j < 26; ++j) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        for (int r = m; r <= n; ++r) {
            int l = r - m;
            bool yes = true;
            for (int i = 0; i < 26; ++i) {
                if (pref[r][i] - pref[l][i] < cnt[i]) {
                    yes = false;
                    break;
                }
            }
            if (yes) return true;
        }
        return false;
    }
};