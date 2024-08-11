class Solution {
private:
    int countOnes(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
       vector<vector<int>> vis(n, vector<int>(m, 0));
        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0 ){
                    island++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return island;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m || i<0 || j<0 || vis[i][j]==1 || grid[i][j]!=1) return;

        vis[i][j]=1;
        dfs(grid,vis,i+1,j);
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i,j-1);
        
    }
public:
    int minDays(vector<vector<int>>& grid) {
        
        if(countOnes(grid)!=1) return 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(countOnes(grid)!=1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};
