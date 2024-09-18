class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (triangle[n-1].size(),-1));

        for(int j=n-1;j>=0;j--){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){

                int down = triangle[i][j] + dp[i+1][j];
                int side = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,side);
            }
        }

        return dp[0][0];

    }
};