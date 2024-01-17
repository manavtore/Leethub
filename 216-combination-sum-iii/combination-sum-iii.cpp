class Solution {
public:
    void generateCombo(int k,int n,vector<int>& current,vector<vector<int>>& ans,int sum,int idxel,vector<int>& nums){
        if(current.size()==k && sum==n){
            ans.push_back(current);
            return;
        }
        if((current.size()+1)>k || sum>n ){
            return;
        }
            for(int i=idxel;i<nums.size();i++){
            current.push_back(nums[i]);
            generateCombo(k,n,current,ans,sum+nums[i],i+1,nums);
            current.pop_back();
            }
                
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        generateCombo(k,n,current,ans,0,0,nums);
        return ans;
    }
};