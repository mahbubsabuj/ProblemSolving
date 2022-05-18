class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        int res = 1;
        int start = 0;
        for (int i = 0; i < n; ++i) {   
            //odd
            int left = i, right = i;
            while (right + 1 < n && left - 1 >= 0 && s[left - 1] == s[right + 1]) {
                --left;
                ++right;
            }
            if (right - left + 1 > res) {
                res = right - left + 1;
                start = left;
            }
            //even
            if (i > 0 && s[i - 1] == s[i]) {
                left = i - 1, right = i;
                while (left - 1 >= 0 && right + 1 < n && s[left - 1] == s[right + 1]) {
                    --left;
                    ++right;
                }
                if (right - left + 1 > res) {
                    res = right - left + 1;
                    start = left;
                }
            }
        }
        return s.substr(start, res);
    }
};