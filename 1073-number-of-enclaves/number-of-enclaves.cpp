class Solution {
private:
    void dfs(int row,int col,vector<int>& delRow,vector<int>& delCol,vector<vector<int>>& vis,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;

        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && vis[nRow][nCol]==0 && grid[nRow][nCol]==1){
                dfs(nRow,nCol,delRow,delCol,vis,grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt = 0;
        vector<int> delRow = {-1,0,1,0};
        vector<int> delCol = {0,-1,0,1};
        for(int j=0;j<m;j++){
            if(vis[0][j]!=1 && grid[0][j]==1){
                dfs(0,j,delRow,delCol,vis,grid);
            }

            if(vis[n-1][j]!=1 && grid[n-1][j]==1){
                dfs(n-1,j,delRow,delCol,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && grid[i][0]==1){
                dfs(i,0,delRow,delCol,vis,grid);
            }

            if(vis[i][m-1]==0 && grid[i][m-1]==1){
                dfs(i,m-1,delRow,delCol,vis,grid);
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};