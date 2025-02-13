class Solution {
public:



    uint32_t reverseBits(uint32_t n) {
        // 16 bits exchanged
        n = ((n >> 16) | (n << 16));

        // 8 bits

        n = ((n & 0xFF00FF00) >> 8 | (n & 0x00FF00FF) << 8);

        // 4 bits

        n = ((n & 0xF0F0F0F0) >> 4 | (n & 0x0F0F0F0F) << 4);

        // 2 bits
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);

    // Step 5: Swap adjacent bits
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    
    return n;
    }
};