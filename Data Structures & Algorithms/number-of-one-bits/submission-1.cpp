class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0, num = n;
        while (num != 0) {
            int discarded = num & 1;
            result += discarded;
            num = num / 2;
        }
        return result;
    }
};
