class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int) s.size();
        int m = (int) t.size();
        int cnt[26];
        fill(cnt, cnt + 26, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < m; ++i) {
            --cnt[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) return false;
        }
        return true;
    }
};