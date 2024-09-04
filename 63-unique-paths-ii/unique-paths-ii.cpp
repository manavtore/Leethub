class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int n = obs.size();
        int m = obs[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        if (obs[0][0] == 1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(obs[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up = 0;
                int left = 0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = up + left;
                
            }
        }
        return dp[n-1][m-1];
    }
};