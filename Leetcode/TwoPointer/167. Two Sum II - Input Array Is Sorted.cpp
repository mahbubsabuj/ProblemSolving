class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = (int) numbers.size();
        int l = 0, r = n - 1;
        vector<int> res;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                res = {l + 1, r + 1};
                break;
            }
            if (numbers[l] + numbers[r] > target) {
                --r;
            } else {
                ++l;
            }
        }
        return res;
    }
};