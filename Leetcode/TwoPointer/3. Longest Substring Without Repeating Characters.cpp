class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> cnt;
        int n = (int) s.size();
        int l = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i]];
            if (cnt[s[i]] >= 2) {
                while (cnt[s[i]] > 1) {
                    --cnt[s[l++]];
                }
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};