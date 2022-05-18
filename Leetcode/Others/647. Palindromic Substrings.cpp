class Solution {
public:
    int countSubstrings(string s) {
        int n = (int) s.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            ++res;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                ++res, --l, ++r;
            }
            if (i > 0 && s[i - 1] == s[i]) {
                ++res;
                l = i - 1, r = i;
                while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                    ++res, --l, ++r;
                }
            }
        }
        return res;
    }
};