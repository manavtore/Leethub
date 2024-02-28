class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long total_sum=0;
        for(int i=0;i<n;i++){
            long long mini=nums[i];
            long long maxi=nums[i];
            for(int j=i;j>=0;j--){
                mini = min(mini,(long long)nums[j]);
                maxi = max(maxi,(long long)nums[j]);
                total_sum +=(maxi-mini);
            }
        }
        return total_sum;
    }
};