class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int odd=0;
        int i=0;
        while(i<n){
            int left=i;
            int right=i;
            odd++;
            while(left-1>=0 && right+1<n){
                if(s[left-1]==s[right+1]){
                    odd++;
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
            i++;
        }
        int even=0;
        int p1=0;
        int p2=1;
        while(p2<n){
            if(s[p1]==s[p2]){
                even++;
                int left=p1;
                int right=p2;
                while(left-1>=0 && right+1<n){
                    if(s[left-1]==s[right+1]){
                        even++;
                        left--;
                        right++;
                    }
                    else{
                        break;
                    }
                }
            }
            
                p1++;
                p2++;
            
        }
        return odd+even;
    }
};