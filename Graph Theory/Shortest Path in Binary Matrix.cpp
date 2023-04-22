//Using Dijkstra Algo
class Solution {
public:
    int dr[8]={-1,-1,0,1,1,1,0,-1};
    int dc[8]={0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size(),m=grid[0].size();
        if(n==1 && m==1) return 1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first,row=it.second.first,col=it.second.second;
            for(int i=0;i<8;i++){
                int nrow=row+dr[i],ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                    if(nrow==n-1 && ncol==n-1) return 2+dis;
                    dist[nrow][ncol]=1+dis;
                    q.push({1+dis,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};
