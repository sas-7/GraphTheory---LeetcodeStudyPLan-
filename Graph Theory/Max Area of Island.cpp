class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]==1){
                    int cnt=0;
                    dfs(row,col,vis,grid,n,m,cnt);
                    count=max(cnt,count);
                }
            }
        }
        return count;
    }
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int n,int m,int &cnt){
        vis[row][col]=1;
        cnt++;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i],ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,vis,grid,n,m,cnt);
            }
        }
    }
};
