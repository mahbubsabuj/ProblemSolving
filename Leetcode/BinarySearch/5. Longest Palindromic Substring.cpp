class Solution {
public:
    bool isPalindrome (string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    int getIdx (string & s, int length) {
        for (int i = length - 1; i < (int) s.size(); ++i) {
            int l = i - length + 1;
            int r = i;
            if (isPalindrome(s, l, r)) {
                return l;
            }
        }
        return -1;
    }
    string longestPalindrome(string s) {
        int length = 1;
        int start = 0;
        for (int parity : {0, 1}) {
            int l = 1, r = (int) s.size();
            if (l % 2 != parity) ++l;
            if (r % 2 != parity) --r;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (mid % 2 != parity) ++mid;
                if (mid > r) break;
                int idx = getIdx(s, mid); //starting idx of the palindrome
                if (idx != -1 && length < mid) {
                    length = mid;
                    start = idx;
                }
                if (idx == -1) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return s.substr(start, length);
    }
};