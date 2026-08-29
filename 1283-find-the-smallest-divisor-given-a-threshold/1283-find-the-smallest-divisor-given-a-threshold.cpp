class Solution {
public:
    int find(vector<int> &nums,int mid){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]+mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int sum=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            sum=find(nums,mid);
            if(sum<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};