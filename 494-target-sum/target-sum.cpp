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
        vector<int> curr(s2+1,0);
        vector<int> prev(s2+1,0);
 
        if (nums[0] == 0) prev[0] = 2; 
        else prev[0] = 1; 

        if (nums[0] != 0 && nums[0] <= s2) prev[nums[0]] = 1; 


        for(int ind=1;ind<n;ind++){
            for(int target = 0 ;target <=s2 ;target++){
                int exclude = prev[target];
                int include = 0;
                if(nums[ind] <= target){
                    include = prev[target-nums[ind]];
                }
                curr[target] = exclude + include;
            }
            prev = curr;
        }
        return prev[s2];
    }
};