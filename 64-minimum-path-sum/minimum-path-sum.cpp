class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }else{
                 int up = grid[i][j];
                   if(i>0){
                    up += dp[i-1][j];
                  }else{
                     up += 1e9;
                  }

                int down = grid[i][j];

                 if(j>0){
                    down += dp[i][j-1];
                  } 
                else{
                    down += 1e9;
                } 

                dp[i][j] = min(up,down);
             }
            }
        }
        return dp[n-1][m-1];   
    }
};