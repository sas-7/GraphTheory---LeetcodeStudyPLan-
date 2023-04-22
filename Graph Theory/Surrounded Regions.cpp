class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(col==0 || row==0 || col==m-1 || row==n-1){
                    if(board[row][col]=='O' && !vis[row][col]) dfs(row,col,n,m,vis,board);
                }
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                    if(board[row][col]=='O' && !vis[row][col]) board[row][col]='X';
            }
        }
    }
    void dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<char>>& board){      
        vis[row][col]=1;          
        for(int i=0;i<4;i++){
            int nrow=row+dr[i],ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,n,m,vis,board);
            }
        }
    }
};
