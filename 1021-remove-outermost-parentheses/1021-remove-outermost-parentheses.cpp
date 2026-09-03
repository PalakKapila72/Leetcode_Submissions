class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int i=0;
        int cnt=0;
        string s1;
        while(i<n){
            if(s[i]=='('){
                cnt++;
                if(cnt>1){
                    s1.push_back(s[i]);
                }
            }
            else if(s[i]==')'){
                cnt--;
                if(cnt>0){
                    s1.push_back(s[i]);
                }
            }
            i++;
        }
        return s1;
    }
};