class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n+1,0);
        vector<int> hash(n,0);
        iota(hash.begin(),hash.end(),0);

        int maxlength = 0;
        int lastIndex = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 >dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxlength){
                maxlength = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;

        while(lastIndex != hash[lastIndex]){
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        sort(ans.begin(),ans.end());
        return ans;
    }   
};