class Solution {
public:
    bool yes (vector<int> cnt, int k) {
        int max_occ = 0;
        for (int i = 0; i < 26; ++i) {
            max_occ = max(max_occ, cnt[i]);
        }
        int all_occ = -max_occ;
        for (int i = 0; i < 26; ++i) {
            all_occ += cnt[i];
        }
        return all_occ <= k;
    }
    int characterReplacement(string s, int k) {
        int l = 0;
        vector<int> cnt(26, 0);
        int n = (int) s.size();
        int res = 0;
        for (int r = 0; r < n; ++r) {
            ++cnt[s[r] - 'A'];
            //do i need more then k replacement from l to r ? 
            //if i don't then max(res, r - l + 1);
            //otherwise remove some characters so that i dont need more then k replacement
            while (!yes(cnt, k)) {
                --cnt[s[l++] - 'A'];
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};