class Solution {
public:
    long long merge(vector<int> &nums,int low,int mid,int high){
        long long count=0;
        int j=mid+1;
        //count reverse pairs
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        //normal merge sort
        int i=low;
        j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low;k<=high;k++){
            nums[k]=temp[k-low];
        }
        return count;
    }
    
    long long mergesort(vector<int> &nums,int low,int high){
        if(low>=high){
            return 0;
        }
        long long count=0;
        int mid=low+(high-low)/2;
        count+=mergesort(nums,low,mid);
        count+=mergesort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergesort(nums,0,n-1);
        
    }
};