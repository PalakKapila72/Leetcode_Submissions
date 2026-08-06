class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it:st){
            int val=it;
            ans=max(1,ans);
            if(st.find(val-1)!=st.end()){
                continue;
            }
            int curr=1;
            while(st.find(val+1)!=st.end()){
                curr+=1;
                val++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};