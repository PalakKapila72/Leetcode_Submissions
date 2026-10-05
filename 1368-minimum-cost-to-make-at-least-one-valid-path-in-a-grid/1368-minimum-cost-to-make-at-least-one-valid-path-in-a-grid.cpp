class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        deque<pair<int,int>> dq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        dq.push_back({0,0});
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        while(!dq.empty()){
            auto [r,c]=dq.front();
            dq.pop_front();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int cost;
                    if(grid[r][c]==i+1){
                        cost=0;
                    }
                    else{
                        cost=1;
                    }
                    if(dist[r][c]+cost<dist[nr][nc]){
                        dist[nr][nc]=dist[r][c]+cost;
                    
                    if(cost==0){
                        dq.push_front({nr,nc});
                    }
                    else{
                        dq.push_back({nr,nc});
                    }
                }
                }

            }
        }
        return dist[n-1][m-1];
    }
};