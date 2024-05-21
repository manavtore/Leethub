class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums,ans,sub,0);
        return ans;
    }
    void solve(vector<int>& nums,vector<vector<int>>& ans,vector<int>& subsets,int index){  
        if(index == nums.size()){
            ans.push_back(subsets);
            return;
        }

        subsets.push_back(nums[index]);
        solve(nums,ans,subsets,index+1);
        subsets.pop_back();
        solve(nums,ans,subsets,index+1);
        
    }
};