class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int count=0;
        vector<int> dr={-1,0,0,1};
        vector<int> dc={0,1,-1,0};

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,i,j});
                    vis[i][j]=1;
                

                }
                else if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        while(!q.empty()){
            int time=q.front()[0];
            int row=q.front()[1];
            int col=q.front()[2];
            q.pop();
            ans=max(ans,time);
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m &&vis[nr][nc]==0 && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({time+1,nr,nc});
                    count--;
                }

            }
        }
        if(count==0){
            return ans;
        }
        return -1;
    }
};