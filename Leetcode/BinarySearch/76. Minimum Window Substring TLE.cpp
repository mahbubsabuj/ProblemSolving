class Solution {
public:
    //TLE
    string minWindow(string s, string t) {
        int l = 1, r = (int) s.size();
        int n = (int) s.size();
        unordered_map<char, int> pref[n + 1];
        for (int i = 1; i <= n; ++i) {
            pref[i][s[i - 1]]++;
            for (char c = 'a'; c <= 'z'; ++c) {
                pref[i][c] += pref[i - 1][c];
            }
            for (char c = 'A'; c <= 'Z'; ++c) {
                pref[i][c] += pref[i - 1][c];
            }
        }
        unordered_map<char, int> count;
        for (int i = 0; i < (int) t.size(); ++i) {
            count[t[i]]++;
        }
        pair<int, int> res;
        auto get = [&] (int length) {
            for (int i = length; i <= n; ++i) {
                int l = i - length;
                int r = i;
                bool yes = true;
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (pref[r][c] - pref[l][c] < count[c]) {
                        yes = false;
                        break;
                    }
                }
                for (char c = 'A'; c <= 'Z'; ++c) {
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