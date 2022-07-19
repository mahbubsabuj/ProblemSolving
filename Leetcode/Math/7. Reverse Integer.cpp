class Solution {
public:
    int reverse(int x) {
        auto overflow = [&] (int now, int last) {
            if (now > INT_MAX / 10) return true;
            if (now < INT_MIN / 10) return true;
            int res = now * 10;
            if (last > 0 && res > INT_MAX - last) return true;
            if (last < 0 && res < INT_MIN - last) return true;
            return false;
        };
        int now = 0;
        while (x != 0) {
            int last = x % 10;
            x /= 10;
            if (overflow(now, last)) {
                return 0;
            }
            now = now * 10 + last;
        }
        return now;
    }
};