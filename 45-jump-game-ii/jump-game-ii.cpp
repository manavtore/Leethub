class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int currentHead=0;
        int farthest = 0;
        for(int i=0;i<nums.size()-1;i++){
            farthest = max(farthest,i+nums[i]);

            if(i==currentHead){
                jump++;
                currentHead=farthest;
            }
        }
        return jump;
    }
};