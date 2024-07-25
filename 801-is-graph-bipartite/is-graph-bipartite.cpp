class Solution {
private:
    bool dfs(int Node,int currColor,vector<vector<int>>& grid,vector<int>& color){
        color[Node]=currColor;

        for(auto it:grid[Node]){
            if(color[it]==-1){
                if(dfs(it,!currColor,grid,color)==false) return false;
            }else if(color[it]==currColor){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> color(n,-1);
      
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                 if(dfs(i,0,grid,color)==false) return false;
            }
        }
        return true;
    }
};