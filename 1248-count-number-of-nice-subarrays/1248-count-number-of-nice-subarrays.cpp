class Solution {
public:
    int solve(vector<int> &nums,int k){
        int n=nums.size();
        int l=0;
        int cnt=0;
        int sum=0;
        for(int r=0;r<n;r++){
            sum+=nums[r]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k==0){
            return solve(nums,k);
        }
        return solve(nums,k)-solve(nums,k-1);
    }
};