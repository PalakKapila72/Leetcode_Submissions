class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentsum=0;;
        int mx=nums[0];
        for(int i=0;i<n;i++){
            currentsum=max(nums[i],currentsum+nums[i]);
            mx=max(mx,currentsum);
        }
        return mx;
    }
};