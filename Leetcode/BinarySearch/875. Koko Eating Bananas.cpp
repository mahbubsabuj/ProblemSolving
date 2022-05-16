class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        int res = 0;
        auto yes = [&] (int k) {
            int hours = 0;
            for (int p : piles) {
                hours += (p + k - 1) / k;
            }
            return hours <= h;
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (yes(mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};