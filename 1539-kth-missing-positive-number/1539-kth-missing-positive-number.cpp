class Solution {
public:
    int find(vector<int>& arr,int mid){
        return arr[mid]-(mid+1);
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=find(arr,mid);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(high==-1){
            return k;
        }//agr pehle hi missing number ho aur k=1 ho
        int missing=arr[high]-(high+1);
        return arr[high]+(k-missing);//agr baad mein mile 
    }
};