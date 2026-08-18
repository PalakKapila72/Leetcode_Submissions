class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int right=n-1;
        int mini=INT_MAX;
        while(low<=right){
            int mid=low+(right-low)/2;
            if(nums[low]<=nums[mid]){
                mini=min(mini,nums[low]);
                low=mid+1;//right side ja rhi hu 
            }
            else if(nums[low]>nums[mid]){
                right=mid;
            }
           
        }
        return mini;
    }
};