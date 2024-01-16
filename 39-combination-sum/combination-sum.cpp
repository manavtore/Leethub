class Solution {
public:
    void generateCombo(int index,int target,vector<vector<int>>& combi,vector<int>& candidates,vector<int>& current){
        if(candidates.size()==index){
            if(target==0){
                combi.push_back(current);
            }
            return;
        }
        if(target>=candidates[index]){
            current.push_back(candidates[index]);
            generateCombo(index,target-candidates[index],combi,candidates,current);
            current.pop_back();
        }
        generateCombo(index+1,target,combi,candidates,current);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combi;
        vector<int> current;
        generateCombo(0,target,combi,candidates,current);
        return combi;
    }
};