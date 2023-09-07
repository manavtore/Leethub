class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        for(int i=0;i<nums.size();i++){
            int square=nums[i]*nums[i];
            nums[i]=square;
        }
       sort(nums.begin(),nums.end());
       return nums;
    }
};