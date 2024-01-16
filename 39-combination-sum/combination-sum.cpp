class Solution {
public:
    void findCombinations(vector<vector<int>>& combinations,vector<int>& current,vector<int>& candidates,int index,int target,int sum){
        if(index==candidates.size()) return;
        if(sum==target){
            combinations.push_back(current);
            return;
        }
        if(sum<=target){
            current.push_back(candidates[index]);
            findCombinations(combinations,current,candidates,index,target,sum+candidates[index]);
            current.pop_back();
            
        }
        findCombinations(combinations,current,candidates,index+1,target,sum);

        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> current;
        findCombinations(combinations,current,candidates,0,target,0);
        return combinations;
    }
};