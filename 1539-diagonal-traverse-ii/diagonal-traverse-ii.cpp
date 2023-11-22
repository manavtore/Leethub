class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxsum=0;
        vector<int> ans;
        unordered_map<int,vector<int>> sumtoelement;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                maxsum = max(maxsum,i+j);
              sumtoelement[i+j].push_back(nums[i][j]);
            }
        }

        for(int i=0;i<=maxsum;i++){
            for(auto value: sumtoelement[i]){
                 ans.push_back(value);
            }
        }
        return ans;
    }
};