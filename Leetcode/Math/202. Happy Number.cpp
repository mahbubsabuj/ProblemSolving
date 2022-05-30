class Solution {
public:
    int get (int n) {
        int res = 0;
        while (n != 0) {
            int last = n % 10;
            res += last * last;
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        for (int i = 1; i <= 10; ++i) {
            n = get(n);
        }
        if (n != 1) return false;
        return true;
    }
};