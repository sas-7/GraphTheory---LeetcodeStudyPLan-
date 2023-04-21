class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col]==0 && grid2[row][col]==1){
                    bool flag=true;
                    dfs(row,col,grid1,grid2,vis,flag,n,m);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int row,int col,vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis,bool &flag,int n,int m){
        if(grid1[row][col]==0) flag=false;
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid2[nrow][ncol]==1){
                    dfs(nrow,ncol,grid1,grid2,vis,flag,n,m);
                }
        }
    }
};
