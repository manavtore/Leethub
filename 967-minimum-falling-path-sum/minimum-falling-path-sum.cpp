class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){

                int up = matrix[i][j] + dp[i-1][j];
                int rightUp = INT_MAX;
                if(j-1>=0){
                    rightUp = matrix[i][j] + dp[i-1][j-1];
                }
                int leftUp = INT_MAX;
                if(j+1<m){
                    leftUp = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(up,min(leftUp,rightUp));
            }
        }

        int maxi = INT_MAX;
        for(int j=0;j<m;j++){
            maxi = min(maxi,dp[n-1][j]);
        }
        return maxi;
    }
};