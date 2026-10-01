class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0;
        int mxlen=0;
        unordered_map<int,int> mp;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;    
            
            if(mp[fruits[l]]==0){
                mp.erase(fruits[l]);
            }
            l++;
            }
            mxlen=max(mxlen,r-l+1);
            


        }
        return mxlen;
    }
};