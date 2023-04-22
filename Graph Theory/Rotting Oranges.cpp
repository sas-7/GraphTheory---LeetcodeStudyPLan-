class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),cntFresh=0;
        queue<pair<int,pair<int,int>>>q;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    q.push({0,{row,col}});
                }
                if(grid[row][col]==1) cntFresh++;
            }
        }
        int time=0,cnt=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int t=it.first,row=it.second.first,col=it.second.second;
            time=max(t,time);
            for(int i=0;i<4;i++) {
                int nrow=row+dr[i],ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
                    cnt++;
                    grid[nrow][ncol]=2;
                    q.push({t+1,{nrow,ncol}});
                }
            }
        }
        if(cnt!=cntFresh) return -1;
        return time;
    }
};
