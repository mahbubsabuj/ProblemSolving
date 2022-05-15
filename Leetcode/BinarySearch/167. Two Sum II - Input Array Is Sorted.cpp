class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = (int) numbers.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r  = n - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (numbers[mid] == target - numbers[i]) {
                    res.push_back(i + 1);
                    res.push_back(mid + 1);
                    break;
                }
                if (numbers[mid] < target - numbers[i]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if ((int) res.size() > 0) break;
        }
        return res;
    }
};