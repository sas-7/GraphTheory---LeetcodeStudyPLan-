class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size(),cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            cnt++;
            int size=q.size();
            while(size--){
                int row=q.front().first,col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i],ncol=col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol] == '.' and !vis[nrow][ncol]){
                        if(nrow==0 || ncol==0 || nrow==n-1 || ncol==m-1) return cnt;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};
