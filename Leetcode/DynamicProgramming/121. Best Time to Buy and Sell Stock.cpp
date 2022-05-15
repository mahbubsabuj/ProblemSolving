class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        int n = (int) p.size();
        int min_price = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = max(res, p[i] - min_price);
            min_price = min(min_price, p[i]);
        }
        return res;
    }
};