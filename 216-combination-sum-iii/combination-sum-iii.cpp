class Solution {
public:
    void generateCombo(int k,int n,vector<int>& current,vector<vector<int>>& ans,int sum,int idxel){
        if(current.size()==k && sum==n){
            ans.push_back(current);
            return;
        }
        if((current.size()+1)>k || sum>n ){
            return;
        }
            for(int i=idxel;i<=9;i++){
            current.push_back(i);
            generateCombo(k,n,current,ans,sum+i,i+1);
            current.pop_back();
            }
                
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        generateCombo(k,n,current,ans,0,1);
        return ans;
    }
};