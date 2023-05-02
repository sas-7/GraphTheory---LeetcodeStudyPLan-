class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int findMaxFish(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]>0){
                    int sum=0;
                    dfs(row,col,vis,grid,sum,n,m);
                    cnt=max(cnt,sum);
                }
            }
        }
        return cnt;
    }
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int &sum,int n,int m){
        vis[row][col]=1;
        sum+=grid[row][col];
        for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && !vis[nrow][ncol]){
                    dfs(nrow,ncol,vis,grid,sum,n,m);
                }
        }
    }
};
