class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> grid2(m,vector<int>(n));
          
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            int indexin2d = ((i * n + j) + k) % (m * n);
                int x= indexin2d/n;
                int y= indexin2d%n;
              
             grid2[x][y]= grid[i][j];
             

            }
        }

      return grid2;
    }
};