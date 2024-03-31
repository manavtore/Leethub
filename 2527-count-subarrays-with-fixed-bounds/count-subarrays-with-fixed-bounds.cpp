class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int badi=-1,mini=-1,maxi=-1,n = nums.size();
        long long ans=0;

        for(int i=0;i<n;i++){
            if(nums[i] <minK || nums[i]>maxK) badi=i;
            if(nums[i]==minK) mini = i;
            if(nums[i]==maxK) maxi = i;
            ans+= max(0,min(mini,maxi)-badi); 
        }
        return ans;
    }
};