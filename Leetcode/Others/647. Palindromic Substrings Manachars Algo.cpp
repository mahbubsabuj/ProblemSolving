class Solution {
public:
    vector<vector<int>> p;
    void construct (string & s) {
        int n = (int) s.size();
        p.clear();
        p.resize(2, vector<int> (n, 0));
        for (int z = 0, l = 0, r = 0; z < 2; ++z, l = 0, r = 0) {
            for (int i = 0; i < n; ++i) {
                if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
                int L = i - p[z][i], R = i + p[z][i] - !z;
                while (L - 1 >= 0 and R + 1 < n and s[L - 1] == s[R + 1]) {
                    ++p[z][i];
                    --L, ++R;
                }
                if (R > r) l = L, r = R;
            }
        }
    }
 
    bool query (int l, int r) {
        if (r - l + 1 == 1) return true;
        int len = r - l + 1;
        int mid = l + (r - l) / 2;
        if (len & 1) {
            if (mid - p[1][mid] <= l and mid + p[1][mid] >= r) {
                return true;
            }
        } else {
            ++mid;
            if (mid - p[0][mid] <= l and mid + p[0][mid] - 1 >= r) {
                return true;
            }
        }
        return false;
    }
    int countSubstrings(string s) {
        construct(s);
        int res = 0;
        for (int l = 0; l < (int) s.size(); ++l) {
            for (int r = l; r < (int) s.size(); ++r) {
                res += query(l, r);
            }
        }
        return res;
    }
};