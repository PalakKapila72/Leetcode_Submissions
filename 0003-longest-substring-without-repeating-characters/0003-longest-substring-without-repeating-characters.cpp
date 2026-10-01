class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        int l=0;
        int r=0;
        int mxlen=0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            mxlen=max(mxlen,r-l+1);
            r++;

        }
        return mxlen;

        
    }
};