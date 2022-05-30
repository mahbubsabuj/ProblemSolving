class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        while (!digits.empty()) {
            int sum = carry + digits.back();
            if (sum > 9) {
                carry = 1;
            } else {
                carry = 0;
            }
            digits.pop_back();
            res.push_back(sum % 10);
        }
        if (carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};