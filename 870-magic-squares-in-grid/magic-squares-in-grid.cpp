class Solution {
private:
    bool magicQuid(vector<vector<int>>& grid,int row,int col){

        set<int> st;

        for(int i=row;i<=row+2;i++){
            for(int j=col;j<=col+2;j++){
                int num = grid[i][j];
                if(num<1 || num>9 || st.find(num)!=st.end() ){
                    return false;
                }
                st.insert(num);
            }
        }

        int sum1 = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        int sum2 = grid[row+1][col] + grid[row+1][col+1] + grid[row+1][col+2];
        int sum3 = grid[row+2][col] + grid[row+2][col+1] + grid[row+2][col+2];

        int sum4 = grid[row][col] + grid[row+1][col] + grid[row+2][col];
        int sum5 = grid[row][col+1] + grid[row+1][col+1] + grid[row+2][col+1];
        int sum6 = grid[row][col+2] + grid[row+1][col+2] + grid[row+2][col+2];

        int sum7 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int sum8 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];

        return sum1 == 15 && sum2==15 && sum3==15 && sum4==15 && sum5==15 && sum6==15 && sum7==15 &&  sum8==15;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt =0;
        for(int i=0;i<=row-3;i++){
            for(int j=0;j<=col-3;j++){
                if(magicQuid(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

