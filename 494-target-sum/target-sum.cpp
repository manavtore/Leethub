class Solution {
    int solve(vector<int>& nums,int ind,int target,vector<vector<int>>& dp){
         if (target < 0) return 0;
        if(ind==0){
            if(target == 0 && nums[0]==0 ){
                return 2;
            }
            if(target==0 || target == nums[0]){
                return 1;
            }
            return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int exclude = solve(nums,ind-1,target,dp);
        int include = 0;
        if(nums[ind] <= target){
            include = solve(nums,ind-1,target-nums[ind],dp);
        }

        return dp[ind][target] = exclude + include;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        
        if(totalSum - target < 0)
            return 0;
        if((totalSum - target) % 2 == 1)
            return 0;
        
        
        int s2 = (totalSum - target) / 2;

         if (s2 < 0) return 0;
         vector<vector<int>> dp(n,vector<int>(s2+ 1,-1));

        return solve(nums,n-1,s2,dp);
    }
};