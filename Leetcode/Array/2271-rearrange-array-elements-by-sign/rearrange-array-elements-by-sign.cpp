class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int> ans(nums.size());
        int posindex=0;
        int negaindex=1;
        
        for(int i=0;i<nums.size();i++){  
            if(nums[i]<0){
                ans[negaindex]=nums[i];
                negaindex+=2;
            }else{
                ans[posindex]=nums[i];
                posindex+=2;
            }
                
            
        }
        return ans;
        
    }
};