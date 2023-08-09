class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's Algorithm
        int sum=0;
        int maxim=nums[0];
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            
            maxim=max(maxim,sum);
            
            if(sum<0){
                sum = 0;
            }
               
        }
        return maxim;
    }
};