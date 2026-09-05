class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        
        unordered_map<char,int> mp2;
        for(int i=0;i<m;i++){
            mp2[t[i]]++;

        }
        int i=0;
        bool ans=false;
        while(i<m){
            while(mp.find(t[i])==mp.end() || mp[t[i]]!=mp2[t[i]]){

                return false;
                i++;
            }
            i++;
        }
        return true;
        
    }
};