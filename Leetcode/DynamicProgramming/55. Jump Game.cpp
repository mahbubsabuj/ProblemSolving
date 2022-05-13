class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int) nums.size();
        int jump = nums[0]; //you can still jump nums[0] position to the left
        for (int i = 1; i < n; ++i) {
            if (jump == 0) return false;
            --jump; //jump to this position
            jump = max(jump, nums[i]); //you can jump jump times from this position
        }
        //if it never returns false from the loop up then you can always jump to n th pos;
        return true;
    }
};
