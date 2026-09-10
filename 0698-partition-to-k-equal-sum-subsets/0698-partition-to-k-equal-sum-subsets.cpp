class Solution {
public:
    bool solve(int mask,int currsum,vector<int> &nums,int req,vector<int> &dp){
        int n=nums.size();
        if(mask==((1<<n)-1)) return true;
        if(dp[mask]!=-1) return dp[mask];
        bool ans=false;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))!=0)continue;
            if(currsum+nums[i]>req) continue;
            int ncurr=(currsum+nums[i])%req;
            int nmask=mask|(1<<i);
            bool newans=solve(nmask,ncurr,nums,req,dp);
            ans=ans||newans;
        }
        return dp[mask]=ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp((1<<n),-1);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int req=sum/k;
        if((sum%k)!=0) return false;
        sort(nums.rbegin(),nums.rend());
        int mx=*max_element(nums.begin(),nums.end());
        if(mx>req){
            return false;
        }
        int mask=0;
        int currsum=0;
        return solve(mask,currsum,nums,req,dp);
    }
};