class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int> lps(s.size(),0);
        int pre=0,suff=1;
        while(suff<s.size()){
            if(s[pre]==s[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        if(lps[n-1]!=0 && n%(n-lps[n-1])==0){
            return true;
        }
        return false;
        
    }
};