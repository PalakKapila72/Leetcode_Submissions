class Solution {
public:
    int find(vector<int> &bloomDay,int k,int mid){
        int cnt=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(mid>=bloomDay[i]){
                cnt++;
                if(cnt==k){
                    ans++;
                    cnt=0;
                }

            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long y=1LL*m*k;
        if(n<y){
            return -1;
        }
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
        int mid=low+(high-low)/2;
        int bouq=find(bloomDay,k,mid);
        if(bouq>=m){
            high=mid-1;

        }
        else{
            low=mid+1;
        }}
        return low;
    }
}; 