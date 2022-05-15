class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int bits[33];
        fill(bits, bits + 33, 0);
        int j = 0;
        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) bits[j] = 1;
            ++j;
        }
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] != 1) continue;
            res += pow(2, i);
        }
        return res;
    }
};