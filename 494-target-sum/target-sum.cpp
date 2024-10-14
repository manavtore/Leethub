class Solution {
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

        vector<vector<int>> dp(n,vector<int>(s2+ 1, 0));

        for(int i=0;i<n;i++){
            if(nums[0]==0 ){
                dp[i][0] = 2;
            }
            if(target == nums[0]){
                dp[i][0] = 1;
            }
        }
        if (nums[0] == 0) dp[0][0] = 2; 
        else dp[0][0] = 1; 
        
        if (nums[0] != 0 && nums[0] <= s2) dp[0][nums[0]] = 1; 


        for(int ind=1;ind<n;ind++){
            for(int target = 0 ;target <=s2 ;target++){
                int exclude = dp[ind-1][target];
                int include = 0;
                if(nums[ind] <= target){
                    include = dp[ind-1][target-nums[ind]];
                }
                dp[ind][target] = exclude + include;
            }
        }
        return dp[n-1][s2];
    }
};