class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(auto value:nums){
            if(value>=0){
                positive.push_back(value);
            }else{
                negative.push_back(value);
            }

        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=positive[i/2];
            }else{
                nums[i]=negative[i/2];
            }

        }
        return nums;
    }
};