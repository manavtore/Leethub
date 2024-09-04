class Solution {
    int unique(int m,int n,vector<vector<int>>& dp){
         if (m == 1 || n == 1) {
            return 1;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        int up = unique(m,n-1,dp);
        int down = unique(m-1,n,dp);

        return dp[m][n]=up+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return unique(m,n,dp);
    }
};