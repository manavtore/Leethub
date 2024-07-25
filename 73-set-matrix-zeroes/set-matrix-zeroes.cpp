class Solution {
private:
    void markRow(int row,int col,vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0;i<n;i++){
            if(mat[i][col]!=0){
                mat[i][col]=-893;
            }
        }
    }  
    void markCol(int row,int col,vector<vector<int>>& mat){
        int m = mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[row][i]!=0){
                mat[row][i]=-893;
            }
        }
    }    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    markCol(i,j,matrix);
                    markRow(i,j,matrix);

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-893){
                    matrix[i][j]=0;
                }
            }
        }
       
    }
};