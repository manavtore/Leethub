class Solution {
    int minimum(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n = triangle.size();
        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down = triangle[i][j] + minimum(i+1,j,triangle,dp);
        int diagonal = triangle[i][j] + minimum(i+1,j+1,triangle,dp);

        return dp[i][j] = min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(triangle[n-1].size(),-1));
        return minimum(0,0,triangle,dp);
    }
};