class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        int i = 0,j = m - 1;

        while(i<n && j>=0){
            if(grid[i][j] < 0){
                cnt += n-i;
                j--;
            }else{
                i++;
            }
        }

       
        return cnt;
    }
};