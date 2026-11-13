class Solution {
public:
    bool checkValidString(string s) {
        int minopen=0;
        int maxopen=0;
        for(char ch:s){
            if(ch=='('){
                minopen++;
                maxopen++;
            }
            else if(ch==')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }
            
        minopen=max(0,minopen);
        if(maxopen<0) return false;
        }
        return minopen==0;
    }
};