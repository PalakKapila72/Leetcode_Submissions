class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        int b1=0;
        int b2=0;
        int rightmost=(xorr&(xorr-1))^xorr;
        for(int i=0;i<n;i++){
            if(nums[i]&rightmost){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        return {b1,b2};
    }
};