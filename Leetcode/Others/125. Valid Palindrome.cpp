class Solution {
public:
    bool isPalindrome(string s) {
        string p;
        for (int i = 0; i < (int) s.size(); ++i) {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    p.push_back((char) (s[i] - 'A' + 97));
                } else {
                    p.push_back(s[i]);
                }
            }
        }
        for (int i = 0; i < (int) p.size() / 2; ++i) {
            if (p[i] != p[(int) p.size() - 1 - i]) return false;
        }
        return true;
    }
};