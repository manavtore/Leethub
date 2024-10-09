class Solution {
    int calculateLength(vector<int>& nums,int ind,int prevind,int n,vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prevind+1]!= -1) return dp[ind][prevind+1];

        int len = calculateLength(nums,ind+1,prevind,n,dp);

        if(prevind == -1 || nums[ind]>nums[prevind]){
            len = max(len,1 + calculateLength(nums,ind+1,ind,n,dp));
        }
        return dp[ind][prevind+1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return calculateLength(nums,0,-1,n,dp);
    }
};