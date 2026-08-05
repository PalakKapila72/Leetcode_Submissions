class Solution {
public:
    void solve(int start,int end,int sum,vector<int> &nums,set<int> &st){
        if(start==end){
            st.insert(sum);
            return;
        }
        solve(start+1,end,sum+nums[start],nums,st);
        solve(start+1,end,sum,nums,st);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        long long g=goal;
        int n=nums.size();
        int mid=n/2;
        set<int> set1,set2;
        solve(0,mid,0,nums,set1);
        solve(mid,n,0,nums,set2);
        long long ans=1e9;
        for(auto it:set1){
            long long a=it;
            long long b=g-a;
            auto at=set2.lower_bound(b);
        
        if(at!=set2.end()){
            long long curr=a+*at;
            long long diff=abs(curr-g);
            ans=min(ans,diff);

        }
        if(at!=set2.begin()){
            at--;
            long long curr=a+*at;
            long long diff=abs(curr-g);
            ans=min(ans,diff);
            if(ans==0){
                return 0;
            }
        }
        }
    
        return ans;
        
    }
};