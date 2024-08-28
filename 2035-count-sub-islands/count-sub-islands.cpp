class Solution {
public:
    void dfs1(vector<vector<int>> &grid,vector<vector<int>> &vis , int i , int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return ;
        }
        grid[i][j]=0;
        dfs1(grid,vis,i-1,j);
        dfs1(grid,vis,i,j-1);
        dfs1(grid,vis,i+1,j);
        dfs1(grid,vis,i,j+1);
    }
    void dfs2(vector<vector<int>> &grid,vector<vector<int>> &vis , int i , int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]){
            return ;
        }
        vis[i][j]=1;
        dfs2(grid,vis,i-1,j);
        dfs2(grid,vis,i,j-1);
        dfs2(grid,vis,i+1,j);
        dfs2(grid,vis,i,j+1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==0 && grid2[i][j]==1){
                    dfs1(grid2,grid1,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && !vis[i][j]){
                    dfs2(grid2,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};