class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long lsum=nums[0]+nums[1];
        long long ans=-1;
        for(int i=2;i<nums.size();i++){
            if(lsum>nums[i]){
                ans=max(ans,lsum+nums[i]);
            }
            lsum+=nums[i];
        }
        return ans;
    }
};