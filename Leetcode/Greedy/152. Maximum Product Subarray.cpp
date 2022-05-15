class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> segs_without_zero;
        int l = -1;
        bool zero = false;
        int max_element = INT_MIN;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            max_element = max(max_element, nums[i]);
            if (nums[i] == 0) {
                zero = true;
                if (l == -1) continue;
                segs_without_zero.push_back(make_pair(l, i - 1));
                l = -1;
            } else {
                if (l == -1) {
                    l = i;
                }
            }
        }
        if (l != -1) segs_without_zero.push_back(make_pair(l, n - 1));
        auto get_ans = [&] (int l, int r) {
            int product = 1;
            for (int i = l; i <= r; ++i) {
                product *= nums[i];
            }
            vector<int> neg_idx;
            for (int i = l; i <= r; ++i) {
                if (nums[i] < 0) neg_idx.push_back(i);
            }
            int ans_left = 1, ans_right = 1;
            if ((int) neg_idx.size() % 2 == 0) return product;
            if (r - l + 1 == 1) {
                return nums[l];
            }
            if (neg_idx[0] == r) {
                ans_left = 0;
            }
            if (neg_idx.back() == l) {
                ans_right = 0;
            }
            for (int i = neg_idx[0] + 1; i <= r; ++i) {
                ans_left *= nums[i];
            }
            for (int i = l; i < neg_idx.back(); ++i) {
                ans_right *= nums[i];
            }
            return max(ans_left, ans_right);
        };
        int res = 0;
        for (pair<int, int> p : segs_without_zero) {
            res = max(res, get_ans(p.first, p.second));
        }
        if (res == 0) {
            if (zero) return 0;
            return max_element;
        }
        return res;
    }
};