class Solution {
    int robSecure(vector<int>& nums,vector<int>& dp,int ind){
        if(ind==0) return nums[ind];
        if(ind<=0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int left = robSecure(nums,dp,ind-2)  + nums[ind];
        int right = 0 + robSecure(nums,dp,ind-1);
        return dp[ind] = max(left,right);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return robSecure(nums,dp,n-1);
    }
};