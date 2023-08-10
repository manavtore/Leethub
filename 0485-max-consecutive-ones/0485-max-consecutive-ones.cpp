class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak=0;
        int higheststreak=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                streak++;
            }
            else if(nums[i]==0){
                streak=0;
            }
            
            if(streak>higheststreak){
                higheststreak=streak;
            }
        }
        return higheststreak;
    }
};