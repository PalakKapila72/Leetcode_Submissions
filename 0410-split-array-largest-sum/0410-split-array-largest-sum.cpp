class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sub=1;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                if(sum>mid){
                    sub++;
                    sum=nums[i];
                }
            }
            if(sub<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};