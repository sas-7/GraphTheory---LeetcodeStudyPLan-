class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),cnt=0;
        vector<vector<int>>vis=grid;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) q.push({i,j});
            }
        }
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int row=q.front().first,col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i],ncol=col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            
            }
            cnt++;
        }
        return cnt>1?cnt-1:-1;
    }
     // When you can only go 4 directions, the (minimum) number of cells you travel from point A to point B is the Manhattan distance.
    //After each iteration of queue elements, increment distance by 1 as we covered 1 unit distance from all cells in every direction.
};
