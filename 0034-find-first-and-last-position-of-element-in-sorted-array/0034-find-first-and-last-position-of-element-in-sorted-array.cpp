class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=-1;
        int last=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            if(nums[mid1]==target){
                start=mid1;
                high=mid1-1;
            }
            else if(nums[mid1]<target){
                low=mid1+1;
            }
            else{
                high=mid1-1;
            }

        }
        low=0;
        high=n-1;
        while(low<=high){
            int mid2=low+(high-low)/2;
            if(nums[mid2]==target){
                last=mid2;
                low=mid2+1;
            }
            else if(nums[mid2]<target){
                low=mid2+1;
            }
            else{
                high=mid2-1;
            }
        }
        return {start,last};
    }
};