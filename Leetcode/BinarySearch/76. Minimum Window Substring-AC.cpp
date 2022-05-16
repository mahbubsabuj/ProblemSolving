class Solution {
public:
    int convert_to_idx (char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        return (c - 'A') + 26;
    }
    string minWindow(string s, string t) {
        int n = (int) s.size();
        int pref[n + 1][52];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 51; ++j) {
                pref[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ++pref[i][convert_to_idx(s[i - 1])];
            for (int j = 0; j < 52; ++j) {
                pref[i][j] += pref[i - 1][j];
            }
        }
        int count[52];
        fill(count, count + 52, 0);
        for (int i = 0; i < (int) t.size(); ++i) {
            count[convert_to_idx(t[i])]++;
        }
        pair<int, int> res;
        auto get = [&] (int length) {
            for (int i = length; i <= n; ++i) {
                int l = i - length;
                int r = i;
                bool yes = true;
                for (int c = 0; c < 52; ++c) {
                    if (pref[r][c] - pref[l][c] < count[c]) {
                        yes = false;
                        break;
                    }
                }
                if (yes) {
                    return make_pair(i - length, length);
                }
            }
            return make_pair(-1, -1);
        };
        int l = 1, r = (int) s.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            pair<int, int> p = get(mid);
            if (p.first != -1) {
                res = p;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (res.first == -1) return "";
        return s.substr(res.first, res.second);
    }
};