class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> val={-1,-1};
        int maxproduct=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && nums[i]>nums[j]){
                    if(nums[i]+nums[j]==target){
                        if(nums[i]*nums[j]>maxproduct){
                            maxproduct=max(maxproduct,nums[i]*nums[j]);
                            val={i,j};
                        }
                    }
                }
            }
        }
        return val;
    }
};