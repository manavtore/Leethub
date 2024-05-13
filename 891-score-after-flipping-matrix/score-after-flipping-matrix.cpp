class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    grid[i][j] = 1- grid[i][j];
             }
            } 
        }
        for(int i=1;i<n;i++){
            int countOnes =0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==1){
                    countOnes++;
                }
            }
            if(countOnes*2<m){
                for(int j=0;j<m;j++){
                    grid[j][i]=1-grid[j][i];
                }
            }
        }
        int score =0;
        for(int i=0;i<m;i++){
            int countRows=0;
            for(int j=0;j<n;j++){
                countRows += grid[i][j] * pow(2,n-j-1);
            }
            score +=countRows;
        }
        return score;
    }
};