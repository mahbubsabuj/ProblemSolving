class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};