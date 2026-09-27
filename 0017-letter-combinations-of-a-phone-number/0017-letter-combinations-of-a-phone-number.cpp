class Solution {
public:
    void solve(int index,string current,vector<string> &ans,string &digits,vector<string> &mapping){
        if(index==digits.size()){
            ans.push_back(current);
            return;
        }
        int digit=digits[index]-'0';
        string value=mapping[digit];
        for(int i=0;i<value.size();i++){
            current.push_back(value[i]);
            solve(index+1,current,ans,digits,mapping);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string current;
        vector<string> ans;
        vector<string> mapping={
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};
        solve(0,current,ans,digits,mapping);
        return ans;
    }
};