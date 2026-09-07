class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int i=0;
        int len=0;
        int mx=0;
        int start=0;
        while(i<n){
            int left=i;
            int right=i;
            while(left>=0 && right<n && s[left]==s[right]){
                len=right-left+1;
                if(len>mx){
                    mx=len;
                    start=left;
                }
                left--;
                right++;
            }
            i++;
        }
        i=0;
        while(i<n){
            int left=i;
            int right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                len=right-left+1;
                if(len>mx){
                    mx=len;
                    start=left;
                }
                left--;
                right++;
            }
            i++;
        }
        return s.substr(start,mx);
    }
};