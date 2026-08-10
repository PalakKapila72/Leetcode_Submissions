class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int sum=-nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                if(nums[left]+nums[right]==sum){
                    vector<int> a;
                    a.push_back(nums[i]);
                    a.push_back(nums[left]);
                    a.push_back(nums[right]);
                    ans.push_back(a);
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }

                }
                else if(nums[left]+nums[right]>sum){
                    right--;
                }
                else{
                    left++;
                }
            }
            
        }
        return ans;
        
    }
};