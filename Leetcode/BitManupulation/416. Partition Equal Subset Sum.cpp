class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10000> bits;
        bits[0] = 1;
        int sum = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            sum += nums[i];
            bits |= (bits << nums[i]);
        }
        if (sum % 2 != 0) return false;
        if (bits[sum / 2]) return true;
        return false;
    }
};