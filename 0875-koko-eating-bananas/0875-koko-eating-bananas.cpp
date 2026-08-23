class Solution {
public:
    long long find(vector<int> &piles,int mid){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]+mid-1)/mid;//yeh hum ceil ke liye use krte hai
        }
        return ans;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long t=0;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            t=find(piles,mid);
            if(t<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        
       return low; 

    }
};