class Solution {
private:
    int minSum(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0){
            return 1e9;
        } 
         if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = grid[i][j] + minSum(grid,dp,i-1,j);
        int  down = grid[i][j] + minSum(grid,dp,i,j-1);

       
        return dp[i][j]=min(up,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return minSum(grid,dp,n-1,m-1);
    }
};