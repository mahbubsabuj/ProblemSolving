class Solution {
public:
    int findFirstOcc (vector<int> & nums, int target) {
        int l = 0, r = (int) nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
    int findLastOcc (vector<int> & nums, int target) {
        int l = 0, r = (int) nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findFirstOcc(nums, target);
        int r = findLastOcc(nums, target);
        if ((l == -1 || r == -1) || l > r) return vector<int>{-1, -1};
        return vector<int>{l, r};
    }
};