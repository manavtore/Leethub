class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result;
         vector<int> subsets;
         generateSubsets(nums,result,subsets,0);
         return result;
    }
    void generateSubsets(vector<int>& nums,vector<vector<int>>& result,vector<int>& subsets,int index){

        if(index==nums.size()){
            result.push_back(subsets);
            return;
        }
        
            subsets.push_back(nums[index]);
            generateSubsets(nums,result,subsets,index+1);
            subsets.pop_back();
            generateSubsets(nums,result,subsets,index+1);

    }
};