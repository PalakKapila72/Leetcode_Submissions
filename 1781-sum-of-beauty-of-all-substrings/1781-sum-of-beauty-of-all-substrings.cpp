class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int mx=INT_MIN;
                int mn=INT_MAX;
                for(auto it:mp){
                   
                    if(it.second>mx){
                        mx=it.second;
                    }
                    if(it.second<mn){
                        mn=it.second;
                    
                    }
                
                
                }
                sum=sum+mx-mn;
            }
        }
        return sum;
    }
};