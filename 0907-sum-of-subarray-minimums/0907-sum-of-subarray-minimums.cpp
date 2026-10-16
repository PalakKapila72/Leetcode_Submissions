class Solution {
public:
    vector<int> nse(vector<int>& arr){
        int n=arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);     
        }
        return nse;
    }
    vector<int> psee(vector<int> &arr){
        int n=arr.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=(int)(1e9+7);
        long long total=0;
        int n=arr.size();
        vector<int> nseArr(n);
        vector<int> pseeArr(n);
        nseArr=nse(arr);
        pseeArr=psee(arr);
        for(int i=0;i<n;i++){
            long long left=i-pseeArr[i];
            long long right=nseArr[i]-i;
            long long contribution=(1LL*left*right%mod*arr[i])%mod;
            total=(total+contribution)%mod;
        }
        return total;
    
    }
};