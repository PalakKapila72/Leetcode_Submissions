class Solution {
public:
    void solve(int index,string &num,long long target,string &expression,long long result,long long prev,vector<string> &ans){
        if(index==num.size()){
            if(result==target){
                ans.push_back(expression);
            }
            return;
        }
        long long current=0;
        for(int i=index;i<num.size();i++){
            if(i>index && num[index]=='0'){
                break;
            }
            current=current*10+(num[i]-'0');
            string part=num.substr(index,i-index+1);
            if(index==0){
                expression+=part;
                solve(i+1,num,target,expression,current,current,ans);
            
            expression.resize(expression.size()-part.size());}
            else{
                expression+="+"+part;
                solve(i+1,num,target,expression,result+current,current,ans);
                expression.resize(expression.size()-part.size()-1);
                expression+="-"+part;
                solve(i+1,num,target,expression,result-current,-current,ans);
                expression.resize(expression.size()-part.size()-1);
                expression+="*"+part;
                solve(i+1,num,target,expression,result-prev+prev*current,prev*current,ans);
                expression.resize(expression.size()-part.size()-1);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string expression="";
        solve(0,num,target,expression,0,0,ans);
        return ans;
    }
};