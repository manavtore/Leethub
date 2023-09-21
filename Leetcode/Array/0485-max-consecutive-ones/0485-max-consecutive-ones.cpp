class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int streak=0;
        int higheststreak=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                streak++;
                higheststreak=max(streak,higheststreak);
            }
           else 
               streak=0;
        }
        return higheststreak;
    }
};