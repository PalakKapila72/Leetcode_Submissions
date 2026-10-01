class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int mxlen=0;
        int mxfreq=0;
        unordered_map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            mxfreq=max(mxfreq,mp[s[r]]);
            while((r-l+1)-mxfreq>k){
                mp[s[l]]--;
                l++;
            }
            mxlen=max(mxlen,r-l+1);
            r++;

        }
        return mxlen;
    }
};