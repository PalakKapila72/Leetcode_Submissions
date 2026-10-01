class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,mxlen=0;
        while(r<n){
            if(nums[r]==0){
                k--;
            }
             while(k<0){
                while(nums[l]!=0){
                    l++;
                }
                l++;
                k++;
             }
            mxlen=max(mxlen,r-l+1);
            r++;   
        }
        return mxlen;
    }
};