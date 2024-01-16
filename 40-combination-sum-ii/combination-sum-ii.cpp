class Solution {
public:
    void generateCombo(int index,int target,vector<vector<int>>& combi,vector<int>& candidates,vector<int>& current){
            if(target==0){
                combi.push_back(current);
                 return;
            }
           
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            current.push_back(candidates[i]);
            generateCombo(i+1,target-candidates[i],combi,candidates,current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> combi;
        vector<int> current;
        generateCombo(0,target,combi,candidates,current);
        return combi;
    }
};