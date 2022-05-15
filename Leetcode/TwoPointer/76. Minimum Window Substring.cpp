class Solution {
public:
    int convert_to_index (char c) {
        if (c >= 'a' && c <= 'z') {
            return c - 'a';
        } else {
            return c - 'A' + 26;
        }
    }
    string minWindow(string s, string t) {
        int n = (int) s.size();
        int m = (int) t.size();
        //unordered_map<char, int> cnt_s, cnt_t;
        int cnt_s[52], cnt_t[52];
        fill(cnt_s, cnt_s + 52, 0);
        fill(cnt_t, cnt_t + 52, 0);
        for (int i = 0; i < m; ++i) {
            ++cnt_t[convert_to_index(t[i])];
        }
        auto can = [&] () {
            for (int i = 0; i < 52; ++i) {
                if (cnt_t[i] > cnt_s[i]) return false;
            }
            return true;
        };
        int l = 0;
        int ans_l = -1, min_length = n + 1;
        for (int r = 0; r < n; ++r) {
            ++cnt_s[convert_to_index(s[r])];
            if (can()) {
                while (can()) {
                    int idx = convert_to_index(s[l]);
                    if (cnt_s[idx] - 1 >= cnt_t[idx]) {
                        --cnt_s[idx];
                        ++l;
                    } else {
                        break;
                    }
                }
                if (min_length > r - l + 1) {
                    ans_l = l;
                    min_length = r - l + 1;
                }
            }
        }
        if (ans_l == -1) return "";
        return s.substr(ans_l, min_length);
    }
};