class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st1;
        stack<int> st2;
        int n=arr.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        
        for(int i=0;i<n;i++){
            int current=arr[i];
            while(!st1.empty() && arr[st1.top()]>current){
                st1.pop();
            }
            if(!st1.empty()){
                pse[i]=st1.top();
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            int current=arr[i];
            while(!st2.empty() && arr[st2.top()]>=current){
                st2.pop();
            }
            if(!st2.empty()){
                nse[i]=st2.top();
            }
            st2.push(i);
        }
        long long ans=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            long long curr=1LL*(nse[i]-i)*(i-pse[i])*arr[i];
            ans=(ans+curr)%mod;
        }
        return ans;
       
    }
};