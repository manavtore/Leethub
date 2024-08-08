class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       int top = 0;
       int bottom = n-1;
       int left = 0;
       int right = n-1;
       int cnt = 1;
       vector<vector<int>> mat(n, vector<int>(n, 0));
       while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                mat[top][i]=cnt;
                cnt++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                mat[i][right]=cnt;
                cnt++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    mat[bottom][i]=cnt;
                    cnt++;
             }
             bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    mat[i][left]=cnt;
                    cnt++;
                }
                left++;
            }
       }
       return mat;
    }
};