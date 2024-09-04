class Solution {
    int unique(vector<vector<int>>& obs,int n,int m,vector<vector<int>>& dp){
        if (n < 0 || m < 0) return 0;
        if(obs[n][m]==1) return 0;
        if(n==0 && m==0)return 1;
        
         if(dp[n][m]!=-1) return dp[n][m];
        int up = unique(obs,n-1,m,dp);
        int left = unique(obs,n,m-1,dp);

        return dp[n][m] = up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return unique(obs,m-1,n-1,dp);
    }
};