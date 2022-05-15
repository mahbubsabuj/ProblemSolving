class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int bit = 0; bit < 25; ++bit) {
                if (i & (1 << bit)) {
                    ++res[i];
                }
            }
        }
        return res;
    }
};