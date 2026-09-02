class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()){
            return s1.length()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int same=1e8,replace=1e8,remove=1e8,insert=1e8;
        if(s1[i]==s2[j]){
            same=solve(i+1,j+1,s1,s2,dp);
        }
        else{
            replace=1+solve(i+1,j+1,s1,s2,dp);
            remove=1+solve(i+1,j,s1,s2,dp);
            insert=1+solve(i,j+1,s1,s2,dp);
        }
        return dp[i][j]=min({same,replace,remove,insert});

    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,word1,word2,dp);
    }
};