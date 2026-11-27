class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = static_cast<uint32_t>(n);
        uint32_t y = 0;

        for (int i = 0; i < 32; i++) {
            uint32_t bit = (x >> i) & 1U;
            y = (y << 1) | bit;
        }

        return static_cast<int>(y);
    }
};
