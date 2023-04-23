class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    queue<pair<int,pair<int,int>>>q;
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,n,m,grid);
                    flag=false;
                    break;
                } 
            }
           if(!flag) break;
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first,row=it.second.first,col=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i],ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[nrow][ncol]==1) return dis;
                    if(grid[nrow][ncol]==0){
                        grid[nrow][ncol]=-1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;   
    }
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid){      
        grid[row][col]=2;  
        q.push({0,{row,col}});             
        for(int i=0;i<4;i++){
            int nrow=row+dr[i],ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                dfs(nrow,ncol,n,m,grid);
            }
        }
    }
};
