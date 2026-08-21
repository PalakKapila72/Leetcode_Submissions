class Solution {
public:
    void lpsfind(vector<int> &lps,string needle){
        int pre=0,suff=1;
        while(suff<needle.size()){
            if(needle[pre]==needle[suff]){
                lps[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
                if(pre==0){
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        int first=0,second=0;
        vector<int> lps(needle.size(),0);
        lpsfind(lps,needle);
        while(first<haystack.size()&&second<needle.size()){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }
        if(second==needle.size()){
            return first-second;
        }
        return -1;
    }
};