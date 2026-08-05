class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;

        int ans=0;
        int n=s.length();
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
        
        ans=max(ans,r-l+1);
        r++;
        }
        return ans;
        
    }
};