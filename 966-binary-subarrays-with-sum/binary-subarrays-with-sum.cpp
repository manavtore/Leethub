class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int sum=nums[i];
            if(sum==goal) count++;
             for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum==goal) count++;
             }
        }
        return count;
    }
};