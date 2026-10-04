class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int minlen=1e9;
        int sindex=-1;
        int l=0,r=0;
        int cnt=0;
        int hash[256]={0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                cnt=cnt+1;
                
            }
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;

                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt=cnt-1;
                }
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};