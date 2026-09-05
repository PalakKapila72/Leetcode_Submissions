class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int depth=0;
        int mxdepth=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                depth++;
                mxdepth=max(depth,mxdepth);
            }
            else if(s[i]==')'){
                depth--;
            }

        }
        return mxdepth;
    }
};