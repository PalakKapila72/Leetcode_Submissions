class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        //number of set bits
        return __builtin_popcount(ans);
    }
};