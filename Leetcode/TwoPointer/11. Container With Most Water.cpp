class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int) height.size() - 1;
        int res = min(height[l], height[r]) * (r - l);
        while (l < r) {
            if (height[r] > height[l]) ++l;
            else --r;
            res = max(res, min(height[l], height[r]) * (r - l));
        }
        return res;
    }
};

