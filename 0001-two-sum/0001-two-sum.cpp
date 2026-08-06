class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int current=nums[i];
            int need=target-current;
            if(mp.find(need)!=mp.end()){
                return {i,mp[need]};
            }
            mp[current]=i;
          


        }
        return {};
        
        
    }
};