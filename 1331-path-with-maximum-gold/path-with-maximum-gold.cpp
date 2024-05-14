class Solution {
public:
    int findMax(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || visited[i][j]){
            return 0;
        }


        visited[i][j]=true;
        int totalsum = grid[i][j];

        int up = findMax(grid,i+1,j,visited);
        int down = findMax(grid,i-1,j,visited);
        int left = findMax(grid,i,j+1,visited);
        int right = findMax(grid,i,j-1,visited);

        visited[i][j]=false;
        return totalsum+max({up,down,left,right});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxGold = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                     maxGold = max(maxGold,findMax(grid,i,j,visited));
                }
            }
        }
        return maxGold;
    }
};