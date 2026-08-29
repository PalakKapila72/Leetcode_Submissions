class Solution {
public:
    int find(vector<int> &weights,int mid){
        int day=1;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(sum+weights[i]>mid){
                day++;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int day=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            day=find(weights,mid);
            if(day<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
        return low;
    }
};