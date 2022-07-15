class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //small big small big
        //big small big small
        int n = (int) nums.size();
        auto get = [&] (bool sign) {
            int length = 1;
            int now = nums[0];
            //if sign == true then minimize now else maximize now;
            for (int i = 1; i < n; ++i) {
                if (sign) {
                    if (now < nums[i]) {
                        sign = false;
                        now = nums[i];
                        ++length;
                    } else {
                        now = min(now, nums[i]);
                    }
                } else {
                    if (now > nums[i]) {
                        sign = true;
                        now = nums[i];
                        ++length;
                    } else {
                        now = max(now, nums[i]);
                    }
                }
            }
            return length;
        };
        return max(get(true), get(false));
    }
};