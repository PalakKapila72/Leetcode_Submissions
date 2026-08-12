class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int suffix=1;
        int prefix=1;
        int mx;
        int ans=nums[0];
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-1-i];
            
            if(prefix>suffix){
                mx=prefix;
            }else{
                mx=suffix;
            }
            ans=max(mx,ans);

        }
        return ans;

        
    }
};