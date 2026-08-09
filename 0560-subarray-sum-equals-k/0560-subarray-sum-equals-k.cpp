class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int cnt=0;
        int prefixsum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixsum=prefixsum+nums[i];
            
            int need=prefixsum-k;
            if(mp.find(need)!=mp.end()){
                cnt+=mp[need];
            }
            mp[prefixsum]++;
            
        }
        return cnt;
    }
};