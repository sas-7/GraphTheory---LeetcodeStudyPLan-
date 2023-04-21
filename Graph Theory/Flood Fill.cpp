class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initCol=image[sr][sc];
        int n=image.size(),m=image[0].size();
        dfs(sr,sc,image,initCol,color,n,m);
        return image;
    }
    void dfs(int row,int col,vector<vector<int>>& image,int initCol,int color,int n,int m){
        image[row][col]=color;
        for(int i=0;i<4;i++){
            int nrow=dr[i]+row,ncol=dc[i]+col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==initCol && color!=initCol){
                image[nrow][ncol]=color;
                dfs(nrow,ncol,image,initCol,color,n,m);
            }
        }
    }
};