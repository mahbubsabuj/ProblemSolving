class Solution {
public:
    bool isPalindrome (string & s) {
        for (int i = 0; i < (int) s.size() / 2; ++i) {
            if (s[i] != s[(int) s.size() - 1 - i]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = (int) s.size(); 
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            string p = "";
            for (int j = i; j < n; ++j) {
                p.push_back(s[j]);
                cnt += isPalindrome(p);
            }
        }
        return cnt;
    }
};