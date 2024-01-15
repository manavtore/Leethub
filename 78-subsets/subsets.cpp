class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> result;
         vector<int> subsets;
         generateSubsets(nums,result,subsets,0);
         return result;
    }
    void generateSubsets(vector<int>& nums,vector<vector<int>>& result,vector<int>& subsets,int index){

        if(checkDuplicate(subsets,result)==true){
            result.push_back(subsets);
        }
        
        for(int i=index;i<nums.size();i++){
            subsets.push_back(nums[i]);
            generateSubsets(nums,result,subsets,i+1);
            subsets.pop_back();
        }

    }
    bool checkDuplicate(vector<int>& subsets,vector<vector<int>>& result){
       return find(result.begin(),result.end(),subsets) == result.end();

    }
};