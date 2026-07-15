class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        for(int i = 0; i < 32; ++i) {
            int bit = n & 1; // Now bit stores the LSB of n
            
            // Now i will push this bit into ans
            ans <<= 1; // Left shift answer to create room for the extracted bit
            ans = ans | bit;
            
            // Discared the used bit by doing right shift on n
            n >>= 1;
        }
        return ans;
    }
};


