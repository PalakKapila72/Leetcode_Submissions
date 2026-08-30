class Solution {
public:
    int find(vector<int> &nums,int mid){
        int subarrays=1;
        int n=nums.size();
        int i=1;
        int curr=nums[0];
        while(i<n){
            if(curr+nums[i]>mid){
                subarrays++;
                curr=nums[i];
            }
            else{
                curr+=nums[i];
            }
            i++;
        }
        return subarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int subarrays=find(nums,mid);
            if(subarrays>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};