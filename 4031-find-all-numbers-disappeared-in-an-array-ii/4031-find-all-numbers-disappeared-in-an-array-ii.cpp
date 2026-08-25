class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<vector<int>> ans;
        int range=upper-lower+1;
        vector<int> a(range,0);
        for(int x:nums){
            if(x>=lower && x<=upper){
                a[x-lower]=1;
            }
        }
        int i=0;
        while(i<range){
            if(a[i]==1){
                i++;
                continue;
            }
            int start=i;
            while(i<range && a[i]==0){
                i++;
            }
            int end=i-1;
            ans.push_back({start+lower,end+lower});
        }
        return ans;
    }
};