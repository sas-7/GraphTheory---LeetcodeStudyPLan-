class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(col==0 || row==0 || col==m-1 || row==n-1){
                    if(grid[row][col]==0 && !vis[row][col]) dfs(row,col,n,m,vis,grid);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    dfs(i,j,n,m,vis,grid);
                }
            }
        }
        return cnt;
    }
    void dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&grid){      
        vis[row][col]=1;               
        for(int i=0;i<4;i++){
            int nrow=row+dr[i],ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                dfs(nrow,ncol,n,m,vis,grid);
            }
        }
    }
};
